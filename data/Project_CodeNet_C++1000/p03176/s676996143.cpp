// Author : Chi
// created : Thursday 2020-06-04
// Sawal : Practice

//header files
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//namespaces
using    namespace __gnu_pbds;
using    namespace std;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//macros
#define ll 		    long long
#define ss          second
#define ff          first
#define vi          vector<int>
#define vll         vector<long long>
#define pb(x)       push_back(x)
#define TEST  	    int TesT;cin>>TesT;while(TesT--)solve();
#define TEST1       solve();
#define mod         3
#define aLL(x)      x.begin(),x.end()
#define r0n(i,n)    for(ll i = 0; i < n; ++i)
#define r1n(i,n)    for(ll i = 1; i <= n; ++i)
#define pdp(d,i)    fixed<<setprecision(i)<<d
#define CHI         ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define db(...)     __f(#__VA_ARGS__, __VA_ARGS__)                      //for debugging
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
//LOVE ALGO
void solve(){
    int n;
    cin>>n;
    ll a[n];
    ll s[n];
    for(auto &i:a)cin >> i;
    for(auto &i:s)cin >> i;
    map<int,long long>m;
    m[a[0]]=s[0];
    long long ma_a=s[0];

    for(int i=1; i<n; i++){
        ll an=s[i];
        auto it=m.lower_bound(a[i]+1);
        if(it!=m.begin()){
            it--;
            m[a[i]]=it->second;
        }
        m[a[i]]+=an;
        it=m.upper_bound(a[i]);
        while(it!=m.end()&&it->second <= m[a[i]]){
            auto it2=it;
            it2++;
            m.erase(it);
            it=it2;
        }
        ma_a=max(ma_a,m[a[i]]);
    }
    cout<<ma_a;
    }
// Driver Code
int main(){
    CHI
    TEST1
    return 0;
}
