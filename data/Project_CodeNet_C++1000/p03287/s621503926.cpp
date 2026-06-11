#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int main()
{
	LL N, M;
	cin >> N >> M;
	vector<LL> A(N);
	for (int n = 0; n < N; n++)
		cin >> A[n];

	unordered_map<LL, LL> um;
	um[A[0] % M]++;
	for (int n = 1; n < N; n++)
	{
		A[n] += A[n-1];
		um[A[n] % M]++;	
	}
	LL count = 0;
	for (auto i = um.begin(); i != um.end(); i++)
	{
		LL a = i->first, b = i->second;
		count += (b)*(b-1)/2;
	}
	count += um[0];
	cout << count << endl;
}

