#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;


int main() {
    int n;
    cin>>n;
    vector<ll> x(n),y(n),h(n);
    rep(i,n) cin>>x[i]>>y[i]>>h[i];

    rep(cx,101){
        rep(cy,101){
            ll H=0;
            rep(i,n){
                if(h[i]==0) continue;
                H=h[i]+abs(x[i]-cx)+abs(y[i]-cy);
                break;
            }
            bool ok=true;
            rep(i,n){
                ll tmp=max(H-abs(x[i]-cx)-abs(y[i]-cy),0LL);
                if(tmp!=h[i]) ok=false;
            }
            if(ok){
                cout<<cx<<" "<<cy<<" "<<H<<endl;
            }
        }
    }
}