#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)
typedef long long ll;

int main(){
	int N;
	cin >> N;

	vector<pair<int, int>> A(N);
	rep(i, N){
		cin >> A.at(i).first;
		A.at(i).second = 3;
	}
	int sum = 0;
	rep(i, N){
		int tmp = 0;
		if (A.at(i).first % 2){
			tmp = 2;
			A.at(i).second = 1;
		}
		else {
			tmp = 1;
			A.at(i).second = 2;
		}
		rep(n, N){
			if (n == i) continue;
			tmp *= A.at(n).second;
		}
		sum += tmp;
	}
	cout << sum << endl;
}