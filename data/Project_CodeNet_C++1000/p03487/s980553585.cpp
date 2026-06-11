
// Problem : C - Good Sequence
// Contest : AtCoder - AtCoder Beginner Contest 082
// URL : https://atcoder.jp/contests/abc082/tasks/arc087_a
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

void solve()
{
	int n;cin>>n;
	vi v(n);cin>>v;
	map<int,int> mp;
	for(int i:v)
	mp[i]++;
	int cnt=0;
	for(pii p:mp)
	{
		if(p.se>=p.f)
		{
			cnt+=(p.se-p.f);
		}
		else
		cnt+=p.se;
	}
	cout<<cnt;
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
