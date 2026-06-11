#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
auto clk=clock();
 
ll mexp(ll a, ll b, ll m){
    ll ans=1;
    a%=m;
    while(b){
        if(b&1) ans=ans*a%m;
        b>>=1;
        a=a*a%m;
    }
    return ans;
}

double get(ll x){
    ll num = x;
    ll den = 0;
    while(x){
        den += x % 10;
        x /= 10;
    }
    return 1.0 * num / (1.0 * den);

}

int main(){
    IOS
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());


    ll k;
    cin >> k;
    ll cur = 10, d = 10;
    FOR(i,1,k){
        if(i <= 9){
            cout << i << endl;
        }
        else{
            cur += d;
            cout << cur - 1 << endl;
            if(get(cur + d - 1) > get(cur + 10 * d - 1)){
                d *= 10;
            }
        }
    }


    cerr<<endl<<endl<<"Time: "<<fixed<<setprecision(12)<<(long double)(clock()-clk)/CLOCKS_PER_SEC<<" ms"<<endl<<endl;
 
    return 0;
}