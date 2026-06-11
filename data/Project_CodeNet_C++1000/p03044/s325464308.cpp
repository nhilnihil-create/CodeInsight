#include <iostream>
#include <vector>

void dfs(int v, int c, int p, int n, std::vector<int>& color, std::vector<std::vector<std::pair<int, int> > >& G) 
{
	color.at(v) = c;
	
		for (int j = 0; j < G.at(v).size(); j++)
		{
			
			if (G.at(v).at(j).first == p)
				continue;
			if (G.at(v).at(j).second == 1)
			{
				dfs(G.at(v).at(j).first, 1 - c, v, n, color, G);
			}
			else
			{
				dfs(G.at(v).at(j).first, c, v, n, color, G);
			}
		}
}


int main()
{
	int n;
	std::cin >> n;
	std::vector<std::vector<std::pair<int, int> > > G(n, std::vector<std::pair<int, int> > ());
	
	std::vector<int> color(n, -1);
	for (int i = 0; i < n - 1; i++)
	{
		int uv, vv, wv;
		std::pair<int, int> p;
		std::cin >> uv >> vv >> wv;
		uv--;
		vv--;
		wv %= 2;
	
		p.first = vv;
		p.second = wv;
		G.at(uv).push_back(p);
		p.first = uv;
		G.at(vv).push_back(p);
	}
	dfs(0, 0, -1, n, color, G);
	
	for (int i = 0; i < n; i++)
	{
		std::cout << color.at(i) << '\n';
	}

}