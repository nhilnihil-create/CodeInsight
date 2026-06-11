#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N;
	cin >> N;

	vector<long long> a(N);
	rep(i, N) cin >> a.at(i);

	long long ans = 0;
	rep(i, N){
		while (a.at(i) % 2 == 0){
			a.at(i) /= 2;
			ans++;
		}
	}
	cout << ans << endl;
}