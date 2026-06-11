#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N, A, B;
	cin >> N >> A >> B;

	int ans = 0;
	rep(i, N + 1){
		string num = to_string(i);
		int sum = 0;
		rep(j, (int)(num.size())){
			sum += num.at(j) - '0';
		}
		// cout << sum << endl;
		if (A <= sum && sum <= B) ans += i;
	}
	cout << ans << endl;
}