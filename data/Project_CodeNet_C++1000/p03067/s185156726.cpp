//tenka1_2019_a.cpp
//Tue Apr 30 16:36:32 2019

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
	int a,b,c;
	cin >> a >> b >> c;

	if (a<c && c<b){
		cout << "Yes" << endl;
	}else if (a>c && c>b){
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
//	printf("%.4f\n",ans);
}