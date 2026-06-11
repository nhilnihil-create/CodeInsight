#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000;
ll A[N], B[N], C[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x, y, z, want;
	cin >> x >> y >> z >> want;
	for(int i = 0; i < x; i++)
		cin >> A[i];
	for(int i = 0; i < y; i++)
		cin >> B[i];
	for(int i = 0; i < z; i++)
		cin >> C[i];
	sort(C, C + z);
	priority_queue<pair<ll, pair<int, pair<int, int>>>> pq;
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
			pq.push({A[i] + B[j] + C[z - 1], {i, {j, z - 1}}});
	while(want)
	{
		cout << pq.top().first << '\n';
		int i = pq.top().second.first;
		int j = pq.top().second.second.first;
		int k = pq.top().second.second.second;
		pq.pop();
		if(k)
			pq.push({A[i] + B[j] + C[k - 1], {i, {j, k - 1}}});
		want--;
	}
	return 0;
}
