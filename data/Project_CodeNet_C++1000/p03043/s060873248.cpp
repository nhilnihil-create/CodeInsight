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

int main(){
	int n,k;
	cin >> n >> k;
	
	long double ans=0;
	for(int i=1; i<=min(n,k-1); ++i){
		ans += 1/pow(2.0, ceil(log2((double)k/i)));
	}
	if(n <= k-1){
		ans /= (double)n;
	}else{
		ans /= (double)n;
		ans += (double)(n-k+1)/n;
	}
	
	printf("%.12Lf\n",ans);
	
	return 0;
}