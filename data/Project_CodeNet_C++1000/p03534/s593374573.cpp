#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define VSORT(v) sort(v.begin(), v.end())
#define DVSORT(v) sort(v.begin(), v.end(),greater<int>())
#define SORT(v, n) sort(v, v+n)
#define DSORT(v,n) sort(v, v+n,greater<int>())
#define vi vector<int>
#define pb push_back
#define P pair<int,int>
 
template <class T> void chmin(T&a,const T&b) { a = min(a,b); }
template <class T> void chmax(T&a,const T&b) { a = max(a,b); }
 
void print(){cout<<endl;}
template <class Head, class... Tail>
void print(Head&& h,Tail&&... t){ 
	if(sizeof...(t)==0)
		cout<<h;
	else
		cout<<h<<' ';
	print(move(t)...);
}
 
const double EPS =1e-9;
const long INF =2147483647;//32bit 2*1e+9
const long MOD =1e+9+7;
#define PI 3.14159265258979
 
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};
 
int main(void){
	string S;
	int counter[3],min=INF,max=-INF;
	cin>>S;

	REP(i,3) counter[i]=0;
	REP(i,(int)S.length()){
		switch(S[i]){
			case 'a':
				counter[0]++;
				break;
			case 'b':
				counter[1]++;
				break;
			case 'c':
				counter[2]++;
				break;
		}
	}
  REP(i,3){
		chmin(min,counter[i]);
		chmax(max,counter[i]);
	}

	if(abs(min-max)<=1) puts("YES");
	else puts("NO");

	return 0;
}
