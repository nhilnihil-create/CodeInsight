//cod2017final_b.cpp
//Sun Aug  4 18:55:20 2019

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

	int a[3];
	fill(a,a+3,0);
	for (int i=0;i<s.size();i++){
		if (s[i]=='a'){
			a[0]++;
		}else if (s[i]=='b'){
			a[1]++;
		}else {
			a[2]++;
		}
	}

	if (abs(a[0]-a[1])<=1 && 
		abs(a[0]-a[2])<=1 &&
		abs(a[1]-a[2])<=1){
		cout << "YES" << endl;
	}else {
		cout <<"NO" <<endl;
	}
//	printf("%.4f\n",ans);
}