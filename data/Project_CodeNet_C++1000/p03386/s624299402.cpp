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
	llong A, B, K;
	cin >> A >> B >> K;
	if(A+K-1>=B-K+1){
		for(int i=A; i<=B; ++i) cout << i << endl;
	}else{
		for(int i=A; i<=A+K-1; ++i){
			cout << i << endl;
		}
		for(int i=B-K+1; i<=B; ++i){
			cout << i << endl;
		}
	}
}