//nani?
#include<bits/stdc++.h>
#define pi acos(-1);
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define f(i,a,b) for( int i = a; i < b ; i++ )
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define sor(a) sort( a.begin(), a.end() )
#define rsor(a) sort( a.rbegin(), a.rend() )
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef double ld;
using namespace std;
const ll inf=1e10+6;
const ll MOD=1e9+7;
const ll mod=998244353;
// ac cmtr;
const int MX = 1e6+5;
const int LG = 25;
 
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}
 
//---------------------------
 
ll a[MX];

int main(){
    fastio;
    ll n,k;
    cin>>n>>k;
    f(i,0,n) cin>>a[i];
    sort(a,a+n);
    ll rep = inf;
    for(int i = 0 ; i <= n-k ; i++){
        ll aux = a[i];
        ll aux2 = a[i+k-1];
        ll ans = 0;
        if(aux <= 0 && aux2 <= 0){
            ans = max(abs(aux),abs(aux2));
        }
        else if(aux >= 0 && aux2 >= 0){
            ans = max(aux,aux2);
        }
        else{
            ans = min(2*abs(aux) + abs(aux2) ,2*abs(aux2) + abs(aux)); 
        }
        rep = min(rep , ans);
    }
    cout<<rep<<endl;
}