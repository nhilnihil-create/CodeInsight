//第8回シンデレラガール総選挙は是非本田未央ちゃんに投票をお願いします！
//ファンのことも他のアイドルの子たちのことも本当に大事にしてて、今まで周りに色んなものを与えてくれました。
//今度は私たちが未央ちゃんにお返しをする番です。みんなでガラスの靴を履かせてあげましょう！
// #本田未央を一番星に #本田未央を令和のシンデレラガールに #第8回シンデレラガール総選挙
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<int> gr[200100];
int mx,mxi;
void dfs(int v,int u,int d){
	if(mx<d) mx=d,mxi=v;
	rep(i,gr[v].size()){
		int w=gr[v][i];
		if(u==w) continue;
		dfs(w,v,d+1);
	}
}
int main()
{
	int n,a,b;cin>>n;
	rep(i,n){
		cin>>a>>b;gr[a].pb(b);gr[b].pb(a);
	}
	mx=mxi=-1;dfs(1,0,0);
	mx=-1;dfs(mxi,0,0);
	if(mx%3==1) cout<<"Second"<<endl;else cout<<"First"<<endl;
}
