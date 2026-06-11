#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    vector<int> b(N);
    rep(i,N) {
        int tmp ;
        cin >> tmp;
        b[i] = tmp;
    }
    vector<int> ans,tmp;
    bool t;
    while(1) {
        t = true;
        tmp.assign(0,0);
        for (int i=b.size()-1; i>=0; i--) {
            if (i+1==b[i] && t) {
                ans.push_back(i+1);
                t = false;
            }
            else {
                tmp.push_back(b[i]);
            }
        }
        reverse(tmp.begin(),tmp.end());
        b = tmp;
        if (t) {
            break;
        }
        else if (tmp.size()==0) {
            break;
        }
    }

    if (t) {
        cout << -1 << endl;
    }
    else {
        rep(i,N) {
            cout << ans[N-1-i] << endl;
        }
    }
}
