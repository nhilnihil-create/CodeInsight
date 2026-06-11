#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define uid uniform_int_distribution
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define bpop(x) __builtin_popcountll((ulli)x)
#define blead(x) __builtin_clzll((ulli)x)
#define btrail(x) __builtin_ctzll((ulli)x)
const double PI = acos(-1);
template<class my>
using ind_set = tree<my,null_type,less<my>,rb_tree_tag,tree_order_statistics_node_update>;

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define all(vec) vec.begin(), vec.end()
#define fol(i,a,b) for(int i=a;i<b;i++)
#define loop(i,a,b) for(int i=a;i>=b;i--)
#define forr(x,arr) for(auto& x:arr)
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-7
#define sz(x) (int)(x).size()

using lli   = long long;
using lld   = long double;
using ulli  = unsigned long long int;
using pll   = pair<lli, lli>;
using ttt   = pair<lli, pll>;
using vttt  = vector<ttt>;
using vll   = vector<pll>;
using vl    = vector<lli>;
using vi    = vector<int>;
using vvi   = vector<vector<int>>;
using cd    = complex<long double>;

#ifdef tejasp
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.ff); __p(a.ss); cout << "} "; }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";__p(arg1); cout<<endl;
}
template<typename Arg1>
void __t(const char *name, Arg1 &&arg1)
{ cout<<name<<" : { "; for (auto p : arg1) __p(p); cout<<"}"<<endl; }
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(; ;i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	cout.write(names,i)<<" : ";
	__p(arg1);  cout<<"| ";
	__f(names+i+1,args...);
}
template<typename Arg1, typename Arg2>
void __f(const char *names, Arg1 arg1[], Arg2 &&arg2){
    int i=0;
	for(; ;i++) if(names[i]==',') break;
	cout.write(names,i)<<" : { ";
	fol(i,0,arg2) __p(arg1[i]);
	cout << "} "<<endl;
}
#define trace(...) { cout<<"Line:"<<__LINE__<<" | "; __f(#__VA_ARGS__, __VA_ARGS__); }
#define cotra(...) { cout<<"Line:"<<__LINE__<<" | "; __t(#__VA_ARGS__, __VA_ARGS__); }
#else
#define endl '\n'
#define trace(...)
#define cotra(...)
#endif

lli dp[3003][3003];

void tejas_919(int kkkk)
{
    int n;
    cin>>n;
    string s; cin>>s;
    dp[1][1]=1;
    fol(i,1,n)
    {
        fol(j,1,i+1)
        {
            if(s[i-1]=='<')
            {
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][i+2]-=dp[i][j];
            }
            else
            {
                dp[i+1][1]+=dp[i][j];
                dp[i+1][j+1]-=dp[i][j];
            }
        }
        fol(j,1,n+2) dp[i+1][j]+=dp[i+1][j-1];
        fol(j,0,n+2) dp[i+1][j]%=mod;
    }
    lli ans=0;
    fol(i,1,n+1) ans+=dp[n][i];
    ans%=mod;
    cout<<ans<<endl;
}

int main()
{
    #ifndef tejasp
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #endif
    cout << fixed << setprecision(10);
    int t=1;
    //cin>>t;
    fol(i,0,t) { tejas_919(i+1); }
}
