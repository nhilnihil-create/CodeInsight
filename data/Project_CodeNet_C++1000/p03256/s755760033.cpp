#include <bits/stdc++.h>

bool solve();

int main()
{
	if (solve()) puts("Yes");
	else puts("No");
	
	return 0;
}

bool solve()
{
	int N, M;
	scanf("%d%d", &N, &M);

	std::string s;
	std::cin >> s;

	std::vector<std::set<int>> edge(N);
	for (int i{}; i < M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edge[a].insert(b);
		edge[b].insert(a);
	}
	std::vector<int[2]> conseq_ab(N);
	for (int i{}; i < N; i++)
		for (auto& e: edge[i])
			conseq_ab[i][s[e] == 'B']++;


	std::queue<int> unavailable;
	for (int i{}; i < N; i++)
		if (conseq_ab[i][0] == 0 || conseq_ab[i][1] == 0)
			unavailable.push(i);
	while (!unavailable.empty())
	{
		int deleted{unavailable.front()};
		unavailable.pop();
		while (!edge[deleted].empty())
		{
			int conseq{*edge[deleted].begin()};
			edge[deleted].erase(edge[deleted].begin());
			conseq_ab[deleted][s[conseq] == 'B']--;
			if (deleted != conseq)
			{
				edge[conseq].erase(deleted);
				conseq_ab[conseq][s[deleted] == 'B']--;
			}
			if (conseq_ab[conseq][0] == 0 || conseq_ab[conseq][1] == 0)
				unavailable.push(conseq);
		}
	}

	for (auto& e: conseq_ab)
		if (e[0] || e[1])
			return true;
	return false;
}