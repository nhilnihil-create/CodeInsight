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
	int N, M, X;
	cin >> N >> M >> X;
	vector<int> A(M);
	for(int i=0; i<M; ++i) cin >> A[i];
	int left = 0;
	int right = 0;
	for(int i=0; i<M; ++i){
		if(A[i]<X) ++left;
		else ++right;
	}
	cout << min(left, right) << endl;
}