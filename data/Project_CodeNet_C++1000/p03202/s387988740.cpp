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
map<int,int> me;
int a[200100];
int n,m;
bool f;
//meからboより大きいのを消す
void cl(int bo){
	//if(me.size()<1) return;
	//cout<<bo<<endl;
	//map<int,int>::iterator it=me.end();
	//cout<<bo<<endl;
	//it--;
	//cout<<bo<<endl;
	while(me.size()>0 && me.rbegin()->fi>bo){
		me.erase(me.rbegin()->fi);
	}
	//cout<<bo<<endl;
}
void update(int x){
	if(x<1) f=false;
	else{
		me[x]++;
		if(me[x]>=m){
			me[x]=0;update(x-1);
		}
	}
}
bool cal(int mi){
	me.clear();f=true;m=mi;
	rep(i,n-1){
		if(a[i+1]<=a[i]){
			if(a[i+1]<a[i]) cl(a[i+1]);
			update(a[i+1]);
		}
		if(!f) return false;
	}
	return f;
}
int main()
{
	cin>>n;rep(i,n) cin>>a[i];
	int fl=0;
	rep(i,n-1){
		if(a[i+1]<=a[i]) fl=1;
	}
	if(fl<1){
		cout<<1<<endl;return 0;
	}
	int lo=2,hi=n;
	while(hi>lo){
		int mi=(hi+lo)/2;
		if(cal(mi)) hi=mi;else lo=mi+1;
	}
	cout<<lo<<endl;
}
