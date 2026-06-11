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

string S;
int num[30];

signed main(){
	cin>>S;
	int N=S.size();
	int cnt=0;
	REP(i,N){
		num[S[i]-'a']++;
		cnt++;
	}
	if(cnt<26){
		REP(i,26){
			if(num[i]==0){
				S+=char('a'+i);
				cout<<S<<endl;
				return 0;
			}
		}
	}
	else{
		for(int i=0;i<=N-1;i++){
			bool flag=true;
			for(int j=i;j<=N-1;j++){
				if(S[j]<S[j+1]){
					flag=false;
				}
			}
			if(flag==false)continue;
			if(i==0){
				cout<<-1<<endl;
				return 0;
			}
			else{
				string t;
				vector<char> v;
				for(int j=0;j<=i-2;j++){
					t+=S[j];
				}
				for(int j=i;j<=N-1;j++){
					if(S[i-1]<S[j]){
						v.push_back(S[j]);
					}
				}
				sort(v.begin(),v.end());
				cout<<t+v[0]<<endl;
				return 0;
			}
		}
	}
	return 0;
}
