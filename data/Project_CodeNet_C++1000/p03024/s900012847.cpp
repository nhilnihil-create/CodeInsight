//msol2019_b.cpp
//Sun Jun 16 14:36:42 2019

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
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	string s;
	cin >> s;

	int win = 0;
	for (int i=0;i<s.length();i++){
		if (s[i]=='o'){
			win++;
		}
	}

	if (win+15-s.length()>=8){
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
//	printf("%.4f\n",ans);
}