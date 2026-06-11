#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main() {
    int N;
    cin >> N;
    vector<int> D(13,0);

    rep(i,N) {
        int d;
        cin >> d;
        D[d]++;
    }
    vector<int> A(1,0);

    for (int i=1; i<=11; i++) {
        if (D[i]==2) {
            A.push_back(i);
            A.push_back(24-i);
        }
        else if (D[i]>2) {
            A.push_back(i);
            A.push_back(i);
        }
    }

    if (D[0]>0) A.push_back(0);
    if (D[12]==1) A.push_back(12);
    if (D[12]>1) {
        A.push_back(12);
        A.push_back(12);
    }

    int ans = 0;

    for (int bit = 0; bit < (1<<11); ++bit) {
        vector<int> S;
        S = A;
        for (int i=0; i<11; i++) {
            if (D[i+1]!=1) {
                continue;
            }
            else if (bit & (1<<i)) {
                S.push_back(24-(i+1));
            }
            else {
                S.push_back(i+1);
            }
        }
        sort(S.begin(),S.end());
        int tmp = 24;
        rep(i,S.size()-1) {
            tmp = min(tmp,S[i+1]-S[i]);
        }
        tmp = min(tmp,24-S.back());
        ans = max(ans, tmp);

    }
    cout << ans << endl;
    //cout << cnt << endl;
}
