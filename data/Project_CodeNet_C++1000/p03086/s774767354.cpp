//q003.cpp
//Sat Sep 19 15:39:18 2020

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
	string s;
	cin >> s;

	int ans = 0;
	int tmp = 0;
	rep(i,s.length()){
		if (s[i]=='A' || 
			s[i]=='T' ||
			s[i]=='G' ||
			s[i]=='C'){
			tmp++;
		}else{
			ans = max(ans,tmp);
			tmp=0;
		}
	}

	ans = max(ans,tmp);
	cout << ans << endl;
//	printf("%.4f\n",ans);
}