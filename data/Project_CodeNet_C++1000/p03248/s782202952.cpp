#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 2000005
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define vi vector<ll>
#define vp vector<pii>
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

ll mexp(ll a, ll b){
    ll ans=1;
    a%=MOD;
    while(b){
        if(b&1) ans=ans*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return ans;
}

int main(){
    IOS
    string s;
    cin>>s;
    int n=sz(s);
    s='x'+s;
    if(s[1]=='0' || s[n]=='1'){
        cout<<-1;
        return 0;
    }
    
    FOR(i,2,n){
        if(s[i]!=s[n-i]){
            cout<<-1;
            return 0;
        }
    }
    int u=1;
    FOR(i,2,n+1){
        cout<<u<<" "<<i<<endl;
        if(s[i-1]=='1'){
            u=i;
        }
    }


    cerr<<"Time: "<<1.0/CLOCKS_PER_SEC<<" ms"<<endl;
    return 0;
}