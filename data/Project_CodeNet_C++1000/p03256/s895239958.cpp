#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;

struct Node
{
	int id;
	int c;
	bool visited[2] = {0};
	bool processing[2] = {0};
	vector<Node*> ch;
	
	bool dfs(int k);
};

bool Node::dfs(int k)
{
	if(processing[k])
		return true;
	processing[k] = true;
	visited[k] = true;

	for(Node *v : ch) if((k == 0 && c == v->c) || (k == 1 && c != v->c)) {
		if(v->dfs((k+1)%2))
			return true;
	}
	
	processing[k] = false;
	
	return false;
}

int main()
{
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<Node> nodes(n);
	for(int i=0; i<n; ++i) {
		nodes[i].c = s[i] - 'A';
		nodes[i].id = i+1;
	}
	for(int i=0; i<m; ++i)
	{
		int u, v;
		cin >> u >> v; --u, --v;
		nodes[u].ch.push_back(&nodes[v]);
		nodes[v].ch.push_back(&nodes[u]);
	}

	bool ans = 0;
	for(int i=0; !ans && i<n; ++i)
	{
		for(int j=0; !ans && j<2; ++j) {
			if(!nodes[i].visited[j])
				ans |= nodes[i].dfs(j);
		}
	}
	
	cout << (ans ? "Yes" : "No") << "\n";

	return 0;
}
