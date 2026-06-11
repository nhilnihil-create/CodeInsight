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
vector<int> S[1000];
void Calc(){
	int N = rei();
	int K;
	for(K=0;K*(K-1)/2<N;K++);
	if(K*(K-1)/2 != N){
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	int c = 1;
	for(int i=0;i<K;i++){
		for(int j=i+1;j<K;j++){
			S[i].push_back(c);
			S[j].push_back(c++);
		}
	}
	cout << K << endl;
	for(int i=0;i<K;i++){
		cout << S[i].size() << " ";
		for(int j=0;j<S[i].size()-1;j++){
			cout << S[i][j] << " ";
		}
		cout << S[i][S[i].size()-1] << endl;
	}
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}