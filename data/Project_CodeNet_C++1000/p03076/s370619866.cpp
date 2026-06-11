#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;


int main()
{
	int A[5], R[5];
	int N = 5;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		R[i] = i;
	}
	int ans = mod;
	do {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (10 - (sum % 10)) % 10;
			sum += A[R[i]];
		}
		ans = min(ans, sum);
	}while (next_permutation(R, R + N));
	cout << ans << endl;
}
