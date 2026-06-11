#include<bits/stdc++.h>
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb           push_back
#define ff           first
#define ss           second
#define gcd(a, b)    __gcd(a, b)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       v.begin(),v.end()
#define rall(v)      v.rbegin(),v.rend()
#define lllim        2147483648
#define Pi           2*acos(0.0)
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define D(x)         cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define case         int t,cas=1;cin>>t;while(t--)
#define rep(i,a,n)   for(int i=a;i<n;i++)
#define rev(i,n,a)   for(int i=n;i>=a;i--)
#define sim          template<class T

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/


sim > void read(T& a) {
    std::cin>>a;
}
sim > void read(T& a, T& b) {
    std::cin>>a>>b;
}
sim > void read(T& a,T& b, T& c) {
    std::cin>>a>>b>>c;
}

sim > void readvec( std::vector<T>& v, const int n) {
    rep(i,0,n) {
        T p;
        std::cin>>p;
        v.pb(p);
    }
}

using namespace std;
using namespace __gnu_pbds;

const int maxn=1e5+5;


void solve()
{
	
	ll ans=0;
	
	ll a,b,c;
	read(a,b,c);
	ans=min(b/a,c);
	

    cout<<ans<<endl;
}


int main()
{
    //fast_cin;

//case
    {
        // cout<<"Case "<<cas++<<": ";
        solve();

    }

    return 0;
}
