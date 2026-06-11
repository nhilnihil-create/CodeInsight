#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const long long inf = 1e9+7;
const long long mod = 1e9+7;

int main(){
    ll R,G,B,n;
    cin>>R>>G>>B>>n;

    ll ans=0;

    for (ll i=0;i<=n/R;i++) {
        for (ll j=0;j<=n/G;j++) {
            if((n-i*R-j*G)%B==0&&n-i*R-j*G>=0){
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}
