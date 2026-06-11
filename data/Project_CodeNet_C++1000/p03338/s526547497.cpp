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
	int n;
	string s;
	cin >> n >> s;
	
	int ans=0;
	for(int i=0; i<n-1; i++){
		int before[26]={};
		int after[26]={};
		REP(j,n){
			if(j <= i) before[(int)s[j]-(int)'a']=1;
			else after[(int)s[j]-(int)'a']=1;
		}
		
		int count = 0;
		REP(j,26) count += before[j]*after[j];
		chmax(ans, count); 
	}
	
	cout << ans << endl;
	
	
	
	
	return 0;
}