//q3.cpp
//Fri Aug  7 12:56:42 2020

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
	rep(i,s.length()){
		for (int j=i;j<s.length();j++){
			int flag = 1;
			string subs = s.substr(i,j-i+1);
			for(int k=0;k<subs.length();k++){
				if (subs[k]!='A' &&
					subs[k]!='T' &&
					subs[k]!='G' &&
					subs[k]!='C'
					){
					flag = 0;
				}
			}
			if (flag){
				int length = subs.length();
				ans = max(ans,length);
			}
		}
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}