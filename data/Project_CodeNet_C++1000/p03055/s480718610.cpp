#include <bits/stdc++.h>

#define forsn(i,s,n) for(tint i=(s);i<(tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) for(tint i = tint(n)-1; i >= 0; i--)
#define debug(x) cout << #x << " = "  << x << endl

using namespace std;

typedef long long tint;

void imprimirVector (vector<tint> v)
{
	if (!v.empty())
	{ 
		tint p = tint(v.size());
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}
	else
		cout << "[]" << endl;
}

const tint INF = 1000000000000000000;
tint N;

pair<tint,tint> bfs (tint start, const vector<vector<tint> > &ladj)
{
	
	vector<tint> neigh = {start}, new_neigh;
	vector<tint> distance (N,INF);
	distance[start] = 1;
	tint last = start;
	while (!neigh.empty())
	{
		tint actual = neigh.back();
		neigh.pop_back();
		for (const auto &v : ladj[actual])
		{
			if (distance[v] == INF)
			{
				distance[v] = distance[actual]+1;
				new_neigh.push_back(v);
				last = v;
			}
		}
		
		if (neigh.empty())
			neigh.swap(new_neigh);
	}

	return {distance[last],last};
}


int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	while (cin >> N)
	{
		vector<vector<tint> > ladj (N);
		forn(i,N-1)
		{
			tint a,b;
			cin >> a >> b;
			ladj[a-1].push_back(b-1);
			ladj[b-1].push_back(a-1);
		}
		if (bfs(bfs(0,ladj).second,ladj).first % 3 == 2)
			cout << "Second\n";
		else
			cout << "First\n";
		
		
		
		
	}
	
	
	return 0;
}




