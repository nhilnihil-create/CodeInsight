//011.cpp
//Sat Aug  8 17:47:16 2020

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

	int s[m][n];
	rep(i,m)rep(j,n){
		s[i][j] = 0;
	}

	rep(i,m){
		int k;
		cin >> k;
		rep(j,k){
			int z;
			cin >> z;
			z--;
			s[i][z] = 1;
		}
	}

	vector<int> p(m);
	rep(i,m) cin >> p[i];

	int ans = 0;
	rep(i,1<<n){
		int flag = 1;
		rep(j,m){
			int count = 0;
			rep(k,n){
				if (i>>k&1 && s[j][k]==1){
					count++;
				}
			}
			if (count%2!=p[j]){
				flag = 0;
				break;
			}
		}
		if (flag){
			ans++;
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}