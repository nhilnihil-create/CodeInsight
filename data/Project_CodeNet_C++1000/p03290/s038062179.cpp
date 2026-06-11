#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;

int main(){
    ll D, G; cin >> D >> G;
    vi p(D),c(D),v(D); rep(i,D) cin>>p[i]>>c[i];

    int ans = MOD;

    //R個の全探索(2^R通り)
    for (int bit = 0; bit < (1 << D); bit++) {
        ll tmpscr = 0;
        int tmpnum = 0;
        int pnum = -1;

        for (int i = 0; i < D; i++) {
            //i番目のビットが立っていた時の処理
            if (bit & (1<<i)) {
               tmpscr += 100*(D-i)*p[D-1-i]+c[D-1-i]; //完答
               tmpnum += p[D-1-i];
            } else if(pnum == -1) {
                pnum = i;//完答しないもので最大のスコアを記録
            }
        }

        if(tmpscr >= G) {
            ans = min(ans,tmpnum);
        } else {
            if(pnum != -1)
                if((G-tmpscr+100*(D-pnum)-1)/(100*(D-pnum)) < p[pnum])
                    ans = min(ans,tmpnum+(int)((G-tmpscr+100*(D-pnum)-1)/(100*(D-pnum))));
        }

        
    }
    
    cout << ans << endl;
    return 0;
}
