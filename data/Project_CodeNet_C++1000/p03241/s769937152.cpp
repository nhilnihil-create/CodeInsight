#include<bits/stdc++.h>
using namespace std;
int main() {
	int N, M; cin >> N >> M;
	int res = 1;
	for (int i = 1; i * i <= M; i++)
	{
		if(M % i == 0) {
			if(M / i >= N) res = max(res, i);
			if(i >= N) res = max(res, M / i);
		}
	}
	cout << res << endl;
	return 0;
}
