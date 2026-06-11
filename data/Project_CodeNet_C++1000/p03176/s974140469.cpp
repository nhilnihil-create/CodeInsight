// Vivek Rai
// Blazer_007

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>

#define fastio 		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp	     make_pair
#define inf         0x3f3f3f3f
//#define INF         0x3f3f3f3f3f3f3f3fLL
#define ll          long long
#define pb          push_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define ppi	    pair<ll,pii>
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define see(x)	    cout<<x<<endl;
#define see2(x,y)   cout<<x<<" "<<y<<endl;
#define see3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define bit(x, y)   (((x)>>(y))&1)
#define bpt(x)      (__builtin_popcount(x))
#define bptl(x)     (__builtin_popcountll(x))
#define loop(i,a,b)  for(int i=a;i<b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)
#define N 2000010

using namespace std;
//using namespace __gnu_pbds;

//typedef priority_queue<int> maxHeap;
//typedef priority_queue<int,vector<int>,greater<int>()) minHeap;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(index) -> value at given index or Kth smallest element in set
// order_of_key(X) -> number of elements strictly less than X
//typedef tree<pii , null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

struct flower{
    int hi;
    int bty;
};

ll solve(vector<flower>& v,int n){
    vi dp(n+1);
    dp[0] = 0;
    dp[1] = v[1].bty;
    map<ll,ll> indices;
    indices[v[1].hi] = dp[1];
    ll ans = dp[1];
    loop(i,2,n+1){
        dp[i] = v[i].bty;
        auto it = indices.lower_bound(v[i].hi + 1);
        if(it != indices.begin()){
            it--;
            dp[i] += it->second ;
        }
        indices[v[i].hi] = dp[i] ;
        auto it2 = indices.upper_bound(v[i].hi);
        while(it2 != indices.end() && it2->second <= dp[i]){
            auto temp = it2;
            temp++;
            indices.erase(it2);
            it2 = temp;
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

void solution(){
    int n;
    cin >> n;
    vector<flower> v(n+1);
    loop(i,1,n+1)
        cin >> v[i].hi;
    loop(i,1,n+1)
        cin >> v[i].bty;
    cout << solve(v,n) << endl;
}

signed main(){
    fastio
    // #ifndef ONLINE_JUDGE
    // 	freopen("input.txt", "r" , stdin);
    // 	freopen("output.txt", "w", stdout);
    // #endif

    ll t=1;
    // cin>>t;
    loop(i,1,t+1){
    	//cout<<"Case #"<<i<<": ";
    	solution();
    }
}


