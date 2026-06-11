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
int mi[200100];
int main()
{
	int n,h,w,x,y,now=1;
	cin>>h>>w>>n;
	rep(i,h+10) mi[i]=w+1;mi[h+1]=0;
	rep(i,n){
		cin>>x>>y;mi[x]=min(mi[x],y);
	}
	REP(i,2,h+10){
		if(mi[i]<=now){
			cout<<i-1<<endl;return 0;
		}
		now++;if(now==mi[i]) now--;
	}
}
