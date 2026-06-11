#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int parent[200005], Rank[200005], ind[200005];

void initset(int n)
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		Rank[i] = 0;
	}
}

// Return representative index
int findset(int x)
{
	// Value of representative index is itself
	//cout << "ind" << ind[x] << " par" << parent[x] << " x" << x << "\n";
	if (parent[x] == x)
		return parent[x];
	parent[x] = findset(parent[x]); // Path compression; set value/arrow to representative index
	return parent[x];
}

bool sameset(int x, int y)
{ // Same set would have same rep index
	return findset(x) == findset(y);
}

// Input: 2 nodes which may not be representatives
void mergeset(int x, int y)
{
	//cout << "merge start\n";
	x = findset(x);
	//cout << "y\n";
	y = findset(y);
	if (Rank[x] > Rank[y])
	{
		parent[y] = x;
	}
	else if (Rank[y] > Rank[x])
	{
		parent[x] = y;
	}
	else
	{
		parent[x] = y;
		Rank[y]++;
	}
}

int N, M, P, X, Y, ans = 0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	initset(N + 5);
	for (int i = 1; i <= N; i++)
	{
		cin >> P;
		ind[i] = P;
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> X >> Y;
		mergeset(X, Y);
		// for (int i = 1; i <= N; i++)
		// 	cout << parent[i] << " ";
		// cout << "\n";
	}

	for (int i = 1; i <= N; i++)
	{
		if (findset(i) == findset(ind[i]))
			ans++;
	}
	cout << ans << "\n";
	// for (int i = 1; i <= N; i++)
	// 	cout << ind[i] << " ";
	// cout << "\n";
	// for (int i = 1; i <= N; i++)
	// 	cout << parent[i] << " ";
	// cout << "\n";
	// for (int i = 1; i <= N; i++)
	// 	cout << Rank[i] << " ";
	// cout << "\n";
}
