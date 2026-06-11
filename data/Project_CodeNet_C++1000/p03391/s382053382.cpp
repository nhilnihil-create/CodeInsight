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
#define pint pair<int, int>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;

int main(){
    int n; cin>>n;
    ll m=INF,sum=0;
    FOR(i,0,n){
        ll a,b; cin>>a>>b;
        sum+=a;
        if(a>b) m=min(m,b);
    }
    if(m==INF) co(0);
    else co(sum-m);
}
