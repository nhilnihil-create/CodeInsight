#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}


const int N=100000;
int prime[N+1];
int like[N+1]; // ruisekiwa


int main(){
	int q;
	cin >> q;
	vector<int> l(q),r(q);
	REP(i,q) cin >> l[i] >> r[i];
	
	for(int i=2; i<=N; i++){
		if(prime[i]==1) continue;
		for(int j=i*2; j<=N; j+=i){
			prime[j] = 1;
		}
	}
	
	like[1] = 0;
	for(int i=3; i<=N; i+=2){
		if(prime[i]==0 && prime[(i+1)/2]==0){
			like[i+2] = like[i] + 1;
		}else{
			like[i+2] = like[i];
		}
	}
	
	REP(i,q){
		cout << like[r[i]+2] - like[l[i]] << endl;
	}
	
	
	
	return 0;
}