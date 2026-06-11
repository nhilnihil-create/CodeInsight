#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main() {
	int A, B, K;
	
	vector<int> ans;

	cin >> A >> B >> K;
	int k = K - 1;
	int C = min(A, B);
	for (int i = 1; i <= C; i++)
	{
		if (A % i == 0 && B % i == 0)
		{
			ans.push_back(i);
		}
	}
	reverse(ans.begin(), ans.end());

	cout << ans.at(k) << endl;
}