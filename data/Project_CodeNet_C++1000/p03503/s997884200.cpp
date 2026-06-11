
// Problem : C - Shopping Street
// Contest : AtCoder - AtCoder Beginner Contest 080
// URL : https://atcoder.jp/contests/abc080/tasks/abc080_c
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
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

template<typename T1,typename T2>istream &operator>>(istream &is, vector<pair<T1,T2>> &v) { for (pair<T1,T2> &t : v) is >> t.f>>t.se; return is; }
template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }

const int N=200001;
double pi=acos(-1.0);
int md=1e9+7;
const int INF=1e15;
int dx1[]={0,0,-1,1};
int dy1[]={1,-1,0,0};

template<class T>
T abst(T a)
{return a<0?-a:a;}

template<class T>
T max2(T a,T b){return a>b?a:b;}
template<class T>
T min2(T a,T b){return a<b?a:b;}

void solve()
{
	int n;cin>>n;
	int open[n][5][2];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<2;k++)
			cin>>open[i][j][k];
		}
	}
	int profit[n][11];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=10;j++)
		cin>>profit[i][j];
	}
	int ans=INT_MIN;
	for(int i=1;i<(1<<10);i++)
	{
		int common[n]={0};
		for(int j=0;j<10;j++)
		{
			if(i&(1<<j))
			{
				int x=j/2;
				for(int k=0;k<n;k++)
				common[k]+=open[k][x][j%2];
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++)
		cnt+=profit[i][common[i]];
		ans=max2(ans,cnt);
	}
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
return 0;
}
