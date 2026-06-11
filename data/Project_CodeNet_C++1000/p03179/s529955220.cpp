
// Problem : T - Permutation
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_t
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define eb emplace_back
#define pb push_back
#define size(s) (int)s.size()
#define int long long
#define vi vector<int>
#define vs vector<string>
#define vv vector<vector<int>>
#define pii pair<int,int>
#define m_p(x,y) make_pair(x,y)
#define vp vector<pair<int,int>>
#define setbits(x) __builtin_popcountll(x)
#define f first
#define se second
#define inc(v,n,x) v.assign(n,x)
#define incd(v,n) v.resize(n)
#define iniz(n) memset(n,0,sizeof(n))
#define inin(n) memset(n,-1,sizeof(n))
#define inimi(n) memset(n,0xc0,sizeof(n))
#define inima(n) memset(n,0x3f,sizeof(n))
#define all(v) (v).begin(),(v).end()
using namespace std;
using namespace __gnu_pbds;
template<typename T1,typename T2>istream &operator>>(istream &is, vector<pair<T1,T2>> &v) { for (pair<T1,T2> &t : v) is >> t.f>>t.se; return is; }
template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }
double pi=acos(-1.0);
int md=1e9+7;
const int INF=1e15;
int dx1[]={0,0,-1,1};
int dy1[]={1,-1,0,0};
template<class T>
T abst(T a)
{return a<0?-a:a;}
template<class T> using ordered_set=tree<
T,
null_type,
less_equal<T>,
rb_tree_tag,
tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
struct HASH{
  size_t operator()(const pii &x)const{
    return (size_t) x.first * 37U + (size_t) x.second;}};
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int Pow(int n,int x){int ans=1;
 while(x>0)
 {if(x&1)ans=(ans*n)%md;n=(n*n)%md;x=x>>1;}
 return ans;}

 vi fact,inv;
void inverse(int n)
{inv.resize(n+1);inv[0]=1;
for(int i=1;i<=n;i++)inv[i]=Pow(fact[i],md-2);}
void factorial(int n)
{fact.resize(n+1);fact[0]=1;
for(int i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%md;}
int ncr(int n,int r){
return (((fact[n]*inv[r])%md)*inv[n-r])%md;
}
template<class T>
T max2(T a,T b){return a>b?a:b;}
template<class T>
T min2(T a,T b){return a<b?a:b;}

template<class T>
T maxm(initializer_list <T> l){
	T ans=-INF;
	for(T i:l)
	ans=max2(ans,i);
	return ans;
}
int dp[3001][3001];
void solve()
{
int n;string s;cin>>n>>s;
dp[n][0]=s[n-2]=='>'?1:0;
dp[n][1]=s[n-2]=='<'?1:0;
for(int i=n-1;i>=2;i--)
{
	int t=n-i+1;
	for(int g=0;g<=t;g++)
	{
		if(g==0)
		{
			if(i==n)continue;
			dp[i][g]=0;
			if(s[i-2]=='<')continue;
			for(int j=1;j<=t;j++)
			dp[i][g]=(dp[i][g]+dp[i+1][t-j])%md;
		}
		else
		{
			if(s[i-2]=='<')
			{
				dp[i][g]=(dp[i][g-1]+dp[i+1][g-1])%md;
			}
			else
			{
				dp[i][g]=(dp[i][g-1]-dp[i+1][g-1]+md)%md;
			}
		}
	}
}
int ans=0;
for(int i=0;i<=n;i++)
ans=(ans+dp[2][i])%md;
cout<<ans;
}

int32_t main(){
ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
int t=1;
//cin>>t;
for(int i=1;i<=t;i++)
{
    solve();
}
}
