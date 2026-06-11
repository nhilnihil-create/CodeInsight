#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

#define rep(i,n) for(int i = 0; i < n; i++)
#define rep(j,n) for(int j = 0; j < n; j++)
using namespace std;

int main() {
	int N,M,C;
	double x;
	cin >> N >> M >> C;
	vector<int> B(M);
	int A;
	rep(i, M){
		cin >> B[i];
	}

	int sum = 0, ans = 0;
	rep(i, N){
		rep(j, M){
			cin >> A;
			sum += B[j] * A;
		}
		if(sum + C > 0){
			ans++;
		}
		sum = 0;
	}
	cout << ans;
	return 0;
}