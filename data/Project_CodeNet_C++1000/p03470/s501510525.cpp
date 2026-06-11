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
	vector<int> d(N);
	for(int i=0; i<N; ++i) cin >> d[i];
	sort(d.begin(), d.end());
	int now = d[0];
	int count = 1;
	for(int i=1; i<N; ++i){
		if(d[i]!=now){
			++count;
			now = d[i];
		}
	}
	cout << count << endl;
}

