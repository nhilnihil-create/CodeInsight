#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> storeList(n);
	for(int i = 0; i < n; i++){
		storeList[i] = vector<int>(10);
		for(int j = 0; j < 10; j++){
			cin>>storeList[i][j];
		}
	}
	
	vector<vector<int>> P(n);
	for(int i = 0; i < n; i++){
		P[i] = vector<int>(11);
		for(int j = 0; j <= 10; j++){
			cin>>P[i][j];
		}
	}
	ll ans = -1000000000;
	for(int bit = 1; bit < (1<<10); bit++){
		vector<int> c(n,0);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 10; j++){
				if( bit & (1<<j) && storeList[i][j] == 1){
					c[i]++;
				}
			}
		}
		ll localAns = 0;
		for(int i = 0; i < n; i++){
			localAns += P[i][c[i]];
		}
		ans = max(ans,localAns);
	}
	cout<<ans<<endl;
	return 0;
}
