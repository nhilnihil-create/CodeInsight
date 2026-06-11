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
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for(int i=(a); i < (int)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int d,g;
vector<int> p, c;

int main(){
	
	cin >> d >> g;
	g /= 100;
	p.resize(d+1);
	c.resize(d+1); // 1 based
	REP(i,d){
		cin >> p[i+1] >> c[i+1];
		c[i+1] /= 100;
	}
	
	int ans = 100000000;
	for(int bit=0; bit<(1<<d); bit++){
		int s = 0;
		int count = 0;
		FOR(i,1,d+1){
			if(bit & (1 << (i-1))){
				s += i*p[i] + c[i];
				count += p[i];
			}
		}
		
		if(s >= g){	
			chmin(ans, count);
			continue;
		}
		
		for(int i = d; i >= 1; i--){
			if( !(bit & (1 << (i-1))) ){
				int a = (g-s)/i;
				if((g-s)%i) a++;
				
				if(a <= p[i]-1){
					s += a*i;
					count += a;
				}else{
					s += (p[i]-1)*i;
					count += p[i]-1;
				}
				
				if(s >= g){
					chmin(ans, count);
					break;
				}
			}
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}