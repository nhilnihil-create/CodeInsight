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
	map<string, int> m;
	char last;
	vector<string> W(N);
	for(int i=0; i<N; ++i) cin >> W[i];
	for(int i=0; i<N; ++i){
		++m[W[i]];
		if(m[W[i]]!=1){
			cout << "No" << endl;
			return 0;
		}
		if(i!=0 && W[i][0]!=last){
			cout << "No" << endl;
			return 0;
		}
		last = W[i][W[i].length()-1];
	}
	cout << "Yes" << endl;
}