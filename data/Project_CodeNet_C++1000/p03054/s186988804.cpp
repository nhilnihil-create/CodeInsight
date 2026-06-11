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

const tint MOVE = 4;

map<char,tint> mapping = {{'U',0},{'R',1},{'D',2},{'L',3}}; // (x+2)%4 gives the opposite

int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint H,W,N,sr,sc;
	string s,t;
		
	while (cin >> H >> W >> N  >> sr >> sc >> s >> t)
	{
		
		vector<tint> dir_limit (MOVE);
		dir_limit[0] = sr;     // UP
		dir_limit[1] = W-sc+1; // RIGHT
		dir_limit[2] = H-sr+1; // DOWN
		dir_limit[3] = sc; // LEFT
		vector<tint> dir (MOVE,0);
		//~ imprimirVector(dir_limit);
		bool out_of_board = false;
		forn(i,N)
		{
			dir[mapping[s[i]]]++;
			//~ imprimirVector(dir);
			if (dir[mapping[s[i]]] >= dir_limit[mapping[s[i]]])
				out_of_board = true;
			if (dir[(mapping[t[i]]+2)%4] >= -dir_limit[mapping[t[i]]]+2)
				dir[(mapping[t[i]]+2)%4]--;
			//~ imprimirVector(dir);
			//~ cout << "------" << endl;
		}
		if (out_of_board)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	
	return 0;
}




