//q011.cpp
//Wed Sep 23 22:26:44 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n,m;
	cin >> n >> m;

	int b[m][n];
	rep(i,m)rep(j,n)b[i][j]=0;

	rep(i,m){
		int k;
		cin >> k;
		rep(j,k){
			int s;
			cin >> s;
			s--;
			b[i][s] = 1;
		}
	}

	int p[m];
	rep(i,m)cin>>p[i];

	int ans = 0;
	rep(i,1<<n){
		int s[m];
		fill(s,s+m,0);
		rep(j,n){
			if(i>>j & 1){
				rep(k,m){
					if(b[k][j]==1){
						s[k]++;
					}
				}
			}
		}
		int flag = 1;
		rep(j,m){
			if (s[j]%2!=p[j]){
				flag = 0;
			}
		}
		if(flag){
			ans++;
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}