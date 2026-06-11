#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

struct SegmentTree
{
	vector<int> data;
	vector<int> size;

	SegmentTree(int n)
	{
		size = vector<int>(n, 1);
		for (int i = 0; i < n; i++)
		{
			data.push_back(i);
		}
	}

	int Root(int n)
	{
		if (data[n] == n)
			return n;

		return Root(data[n]);
	}

	void Union(int n, int m)
	{
		n = Root(n);
		m = Root(m);

		if (Check(n, m))
			return;

		if (size[n] < size[m])
			swap(n, m);

		size[n] += size[m];
		data[m] = n;
	}

	bool Check(int n, int m)
	{
		return Root(n) == Root(m);
	}

	int Size(int n)
	{
		return size[Root(n)];
	}
};

void execute()
{
	int N, M;
	cin >> N >> M;
	vector<int> data(N, 0);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		data[a - 1] = i;
	}

	SegmentTree tree(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		tree.Union(a - 1, b - 1);
	}

	for (int i = 0; i < N; i++)
	{
		if (tree.Check(i, data[i]))
			ans++;
	}

	cout << ans << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}