#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

#define MOD 1000000007

int main(void)
{
    int H,W;
    cin >> H >> W;

    vector<string> S(H);
    REP (i,H) {
        cin >> S[i];
    }

    vector<int> dh{-1, 1, 0, 0};
    vector<int> dw{ 0, 0,-1, 1};

    REP (h,H) {
        REP (w,W) {
            int chk = 0;
            if (S[h][w] == '#') {
                REP (i,4) {
                    const int nh = h + dh[i];
                    const int nw = w + dw[i];

                    if ((nh < 0) || (H <= nh) || (nw < 0) || (W <= nw)) {
                       continue;
                    }

                    if (S[nh][nw] == '#') {
                       chk++;
                    }

                }
                if (chk == 0) {
                    cout << "No" << endl;
                    return 0;
                } 
            }
        }
    }
 
    cout << "Yes" << endl;

    return 0;
}
