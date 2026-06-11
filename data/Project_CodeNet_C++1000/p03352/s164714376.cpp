#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll X;
    cin >> X;
    if(X==1) cout << 1 << endl;
    for(ll x=X;x>0;x--){
        for(ll b=1;b<X;b++){
            for(ll p=2;p<X;p++){
                ll bp = 1;
                for(ll k=1;k<=p;k++){
                    bp*=b;
                }
                if(x==bp){
                    cout << x << endl;
                    return 0;
                }
                if(bp>x) break;
            }
        }
    }
    return 0;
}