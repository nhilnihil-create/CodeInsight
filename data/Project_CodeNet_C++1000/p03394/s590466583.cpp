#include <bits/stdc++.h>
using namespace std;

void solve(long long N){
	if(N == 3) {
		cout << "2 5 63" << endl;
		return;
	}
	int sum = 0;
	vector<int> res;
	for(int i = 2; res.size() < N - 2; ++i) if(i % 2 == 0 || i % 3 == 0) {
		res.push_back(i);
		sum += i;
	}
	int b = res.back(), c = b + 1;
	if(sum % 6 == 1 || sum % 6 == 3 || sum % 6 == 5) {
		while(c % 6 != 3) {
			c++;
		}
	} else {
		while(c % 6 == 1 || c % 6 == 3 || c % 6 == 5) {
			++c;
		}
	}
	sum += c;
	res.push_back(c);

	int t = b + 1;
	while((sum + t) % 6 != 0 || t == c) {
		++t;
	}
	res.push_back(t);

	for(int i = 0; i < N; ++i) {
		cout << res[i] << (i == N - 1 ? "\n" : " ");
	}
}

int main(){	
	long long N;
	scanf("%lld",&N);
	solve(N);
	return 0;
}

