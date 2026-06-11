#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
#include<iomanip>
#include<list>
#include<deque>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define DEB2(X) cout<<X<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define DEB2(X) {}
#define END {}
#endif
typedef long long ll;
#define int ll
#define uset unordered_set
#define umap unordered_map
//typedef std::pair<int,int> P;
struct edge{int to,cost;};
const int INF=100000000000000000;
const int INF2=9223372036854775807;
const int MOD=1000000007;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define min(X,Y) (((int)(X)<(int)(Y))?(X):(Y))
#define max(X,Y) (((int)(X)>(int)(Y))?(X):(Y))
#define NP(X,Y) next_permutation(X,Y)
#define setdouble(X,Y) cout<<fixed<<setprecision(X)<<Y
int ceil2(int a,int b){if(a%b==0){return a/b;}else{return a/b+1;}}
int pow2(int a,int b){int r=1;for(int i=1;i<=b;i++){r*=a;}return r;}
int Log2(int a){int t=0;while(1){if(a==0||a==1){break;}a/=2;t++;}return t;}


int H,W,N;
int X,Y;
string S,T;
vector<pair<int,bool>> A,B;

signed main(){
	cin>>H>>W>>N>>Y>>X>>S>>T;
	Y--,X--;
	int l=0,r=W;
	if(S[N-1]=='L'){
		l++;
	}
	if(S[N-1]=='R'){
		r--;
	}
	for(int i=N-2;0<=i;i--){
		if(T[i]=='L'){
			r=min(r+1,W);
		}
		else if(T[i]=='R'){
			l=max(0,l-1);
		}
		if(S[i]=='L'){
			l=l+1;
		}
		else if(S[i]=='R'){
			r=r-1;
		}
		if(l>=r){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(X<l||r<=X){
		cout<<"NO"<<endl;
		return 0;
	}
	l=0,r=H;
	if(S[N-1]=='U'){
		l++;
	}
	if(S[N-1]=='D'){
		r--;
	}
	for(int i=N-2;0<=i;i--){
		if(T[i]=='U'){
			r=min(r+1,H);
		}
		else if(T[i]=='D'){
			l=max(0,l-1);
		}
		if(S[i]=='U'){
			l=l+1;
		}
		else if(S[i]=='D'){
			r=r-1;
		}
		if(l>=r){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(Y<l||r<=Y){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}
