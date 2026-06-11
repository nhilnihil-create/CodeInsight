#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
	int s;
	cin >> s;
	int count = 1;
	if(s==2 || s==1){
		s=4;
		count = 1;
	}
	while(s!=4){
		if(s%2==0) s/=2;
		else s = 3*s + 1;
		++count;
	}
	cout << count+3 << endl;
}