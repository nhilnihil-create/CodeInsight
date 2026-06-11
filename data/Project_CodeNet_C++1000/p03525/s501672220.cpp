#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 987654321
#define ll long long

int N;
vector<int> v;

int main() // O(n^2) solution
{
	scanf("%d", &N);
	v.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());

	int res = 0, lo, hi;
	for (int i = 1; i < 24; i++)
	{
		lo = 0, hi = 24;

		int chk = 0;
		for (int j = 0; j < N; j++)
		{
			//둘 다 가능하면 어느 쪽이든 상관없다.
			if (v[j] - lo >= i && hi - v[j] >= i) lo = v[j];
			else if ((24 - v[j]) - lo >= i && hi - (24 - v[j]) >= i) hi = 24 - v[j];
			else
			{
				chk = 1;
				break;
			}
		}

		if (chk) break;

		res = i;
	}

	printf("%d", res);
	return 0;
}