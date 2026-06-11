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

int X[200010], A[200010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		A[i] = X[i];
	}
	sort(A, A + N);
	for (int i = 0; i < N; i++) {
		if (X[i] <= A[N / 2 - 1]) cout << A[N / 2] << endl;
		else cout << A[N / 2 - 1] << endl;
	}
}
