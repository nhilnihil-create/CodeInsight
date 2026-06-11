#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
long DP[5001*5001];
int P[5000];
void Calc(){
	int N = rei();
	long A = rei();
	long B = rei();
	for(int i=0;i<N;i++){
		int p = rei()-1;
		P[p] = i+1;
	}
	fill(DP,DP+5001*5001,1000000000000000000);
	DP[0] = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=N;j++){
			if(P[i] < j){
				DP[(i+1)*5001+j] = min(DP[(i+1)*5001+j],DP[i*5001+j]+A);
			}
			else if(P[i] > j){
				DP[(i+1)*5001+j] = min(DP[(i+1)*5001+j],DP[i*5001+j]+B);
				DP[(i+1)*5001+P[i]] = min(DP[(i+1)*5001+P[i]],DP[i*5001+j]);
			}
			else{
				DP[(i+1)*5001+j] = min(DP[(i+1)*5001+j],DP[i*5001+j]);
			}
		}
	}
	long ans = 1000000000000000000;
	for(int i=0;i<=N;i++){
		ans = min(ans,DP[N*5001+i]);
	}
	cout << ans << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}