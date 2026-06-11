#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin>>n;
    ll x[n],y[n],h[n];
    rep(i,n) cin>>x[i]>>y[i]>>h[i];

    rep(cx,101){
        rep(cy,101){
            bool ok=true;
            ll H=0;
            rep(i,n){
                if(h[i]==0) continue;
                H=abs(x[i]-cx)+abs(y[i]-cy)+h[i];
                break;
            }
            if(H<1) ok=false;

            rep(i,n){
            
                ll tmp=max(H-abs(x[i]-cx)-abs(y[i]-cy),0LL);
                if(tmp!=h[i]) ok=false;
            }
            if(ok){
                cout<<cx<<" "<<cy<<" "<<H<<endl;
                return 0;
            }
        }
    }
}

