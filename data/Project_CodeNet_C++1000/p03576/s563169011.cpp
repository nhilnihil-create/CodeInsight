//g++ -std=c++14 test.cpp -o test.out
 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<62)-10e15;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;
 
LL N,K;
LL x[50],y[50];
 
LL ans = INF;

LL max_num(LL a,LL b,LL c,LL d){
	return max(a,max(b,max(c,d)));
}
LL min_num(LL a,LL b,LL c,LL d){
	return min(a,min(b,min(c,d)));
}
 
void solve(){
	for(int a=0;a<N;a++){
		for(int b=0;b<N;b++){
			for(int c=0;c<N;c++){
				for(int d=0;d<N;d++){
					LL right = max_num(x[a],x[b],x[c],x[d]);
					LL upper = max_num(y[a],y[b],y[c],y[d]);
					LL left = min_num(x[a],x[b],x[c],x[d]);
					LL bottom = min_num(y[a],y[b],y[c],y[d]);
					int counter = 0;
					for(int i=0;i<N;i++){
						if(bottom<=y[i] && y[i]<=upper && left<=x[i] && x[i]<=right) counter++;
					}
					if(counter<K) continue;
					ans = min(ans,(right-left)*(upper-bottom));
				}
			}
		}
	}
}
 
int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
    	cin >> x[i] >> y[i];
    }
 
    solve();
 
    cout << ans << endl;
    return 0;
}