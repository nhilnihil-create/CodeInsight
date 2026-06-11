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
	int N;
	cin >> N;
	for(int i=0; i<=N/4; ++i){
		if((N-4*i)%7==0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
