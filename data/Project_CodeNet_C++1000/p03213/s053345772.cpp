#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const double pi = 3.141592653589793;




int main(){
    ll N;
    cin>>N;
    vector<ll> Pr(N+1, 0);
    for(ll i=2; i<=N; i++){
        ll I=i;
        for(ll j=2; j<=i; j++){
            if(I<j)break;
            while(I%j==0){
                Pr[j]++;
                I/=j;
            }
        }
    }
    ll Three, Five, Fifte, Twent, Sevf;
    Three=0;
    Five=0;
    Fifte=0;
    Twent=0;
    Sevf=0;
    rep(i, N+1){
        if(Pr[i]>=2)Three++;
        if(Pr[i]>=4)Five++;
        if(Pr[i]>=14)Fifte++;
        if(Pr[i]>=24)Twent++;
        if(Pr[i]>=74)Sevf++;
      	//cout<<Pr[i]<<endl;
    }
    ll Ans=0;
    Ans+=Five*(Five-1)/2*(Three-2);
    Ans+=Fifte*(Five-1);
    Ans+=Twent*(Three-1);
    Ans+=Sevf;
    cout<<Ans<<endl;
}
    