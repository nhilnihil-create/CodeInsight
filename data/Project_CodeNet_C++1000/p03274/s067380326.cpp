#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, K; cin >> N >> K;
    vector<int> p;
    vector<int> m;
    rep(i, N){
        int x; cin >> x;
        if(x < 0){
            m.push_back(-x);
        } else {
            p.push_back(x);
        }
    }

    int ans = 1001001001;
    int psize = p.size();
    int msize = m.size();
    for (int i = 0; i <= msize; i++){
        int pnum = K-i;
        if(pnum > psize || pnum < 0)continue;
        int left, right;
        if(i == 0){
            left = 0;
        } else {
            left = m[msize-i];
        }
        if(pnum == 0){
            right = 0;
        } else {
            right = p[pnum-1];
        }
        int now = min(left*2+right, left+right*2);
        ans = min(ans, now);
    }

    cout << ans << endl;


    return 0;
}