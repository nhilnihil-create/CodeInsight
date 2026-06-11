//q002.cpp
//Sat Sep 19 15:36:41 2020

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
	int n;
	cin >> n;
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(i%2==0)continue;
		int tmp = 0;
		for (int j=1;j<=i;j++){
			if (i%j==0)tmp++;
		}
		if(tmp==8)ans++;
	}


	cout << ans << endl;
//	printf("%.4f\n",ans);
}