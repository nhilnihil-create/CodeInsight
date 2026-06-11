#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;

int main(){
    int q; cin>>q;
    FOR(i,0,q){
        ll a,b; cin>>a>>b;
        ll k=sqrtl(a*b-1);
        ll ans=2*k-1;
        if(k*(k+1)>a*b-1) ans--;
        if(a==b) ans++;
        co(ans);
    }
}
