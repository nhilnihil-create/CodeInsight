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
//問題文および制約はちゃんと確認しよう！
//サイズは10^5じゃなくて2×10^5とかかもしれないし、重要な制約・条件を見落としているかも
//とりあえずサンプルを読んでから解法を考えよう？
vector<int> out[100100];
int main()
{
	int n,m,t=1;
	cin>>n;
	m=(int)(sqrt(2.0*n));
	if(m*(m+1)/2!=n){
		cout<<"No"<<endl;return 0;
	}
	rep(i,m+1) REP(j,i+1,m+1){
		out[i].pb(t);out[j].pb(t);t++;
	}
	cout<<"Yes"<<endl;
	cout<<m+1<<endl;
	rep(i,m+1){
		cout<<m;
		rep(j,m) cout<<' '<<out[i][j];
		cout<<endl;
	}
}
