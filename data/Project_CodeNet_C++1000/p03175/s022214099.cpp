#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
double pi = acos(-1.0);
const double EPS=1e-9;
#define MOD ll(1e9L+7)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define t() ll tt;cin>>tt;while(tt--) 
#define t2() ll tt2; cin>>tt2; for(ll tti=1;tti<=tt2;tti++)
#define printcj "Case #"<<tti<<": "
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define debug3(x, y,z) cout << #x << " = " << x << "   " << #y << " = " << y << " "<<#z<<" = "<<z<<"\n";
#define debugarray(arr,n,x) { cout << "[" ; for(ll i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"] , "<<#x<<" = "<<x<<'\n';}

vector<vector<ll>>g;
//pll represent dp{white,black}
pll solve(ll source,ll parent)
{
    pll current = {1,1}; //base case if leaf
    for(auto to:g[source]){
        if(to!=parent){
            pll temp = solve(to,source);
            current.first = (current.first* (temp.first + temp.second))%MOD;
            current.second = (current.second*temp.first)%MOD;
        }
    }
    // debug3(source,current.first,current.second);
    return current;
}

int main()
{
    fastio;
    ll n,i,u,v;
    cin>>n;
    g.resize(n+1);
    for(i=0;i<n-1;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pll temp = solve(1,1);
    cout<<(temp.first+temp.second)%MOD<<'\n';    
}
