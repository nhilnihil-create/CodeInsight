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
	int n,index=0;
	cin >> n;
	vector<vector<int>> a(n,vector<int>(3));
	REP(i,n){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	REP(i,n){
		if(a[i][2]!=0){
			index = i;
			break;
		}
	}
	
	int a0 = a[0][0]; a[0][0] = a[index][0]; a[index][0] = a0;
	int a1 = a[0][1]; a[0][1] = a[index][1]; a[index][1] = a1;
	int a2 = a[0][2]; a[0][2] = a[index][2]; a[index][2] = a2;
	
	int X=-1,Y=-1,H=-1;
	bool ok=true;
	REP(x,101){
		REP(y,101){
			int h = 0;
			ok = true;
			REP(k,n){
				if(k==0){
					h = a[k][2] + abs(x-a[k][0]) + abs(y-a[k][1]);
					continue;
				}
				
				int dh = h - abs(x-a[k][0]) - abs(y-a[k][1]);
				if(max(dh,0) !=  a[k][2]){
					ok = false;
					break;
				}
			}
			if(ok){
				X = x;
				Y = y;
				H = h;
			}
		}
	}
	
	printf("%d %d %d\n",X,Y,H);
	
	
	return 0;
}