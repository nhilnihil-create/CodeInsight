#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 16;
const int INFINI = -1e18;
int tab[MAXN][MAXN];

int meilleur[(1<<MAXN)];
int N;

vector <int> creer;

void trouverEnsembles(int in , int tot , int actu)
{
	if (in == N)
	{
		creer.push_back(actu);
		return;
	}
	trouverEnsembles(in + 1 , tot , actu);
	if (tot & (1<<in))
		trouverEnsembles(in + 1 , tot , actu | (1<<in));
}
int recursion(int ensemble)
{
	if (meilleur[ensemble] != INFINI) return meilleur[ensemble];
	if (ensemble == 0) return 0;
	meilleur[ensemble] = 0;
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = i + 1 ; j < N ; j++)
		{
			if ((ensemble & (1<<i)) && (ensemble & (1<<j)))
			{
				meilleur[ensemble] += tab[i][j];
			}
		}
	}
	creer.clear();
	trouverEnsembles(0 , ensemble , 0);
	vector <int> actu;
	for (int i = 0 ; i < creer.size() ; i++)
	{
		actu.push_back(creer[i]);
	}
	for (int i = 0 ; i < actu.size() ; i++)
	{
		meilleur[ensemble] = max(meilleur[ensemble] , recursion(actu[i]) + recursion(ensemble ^ actu[i]));
	}
	return meilleur[ensemble];


}

int32_t main()
{
	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			cin >> tab[i][j];
		}
	}
	for (int i = 0 ; i < (1<<N) ; i++)
	{
		meilleur[i] = INFINI;
	}
	cout<<recursion((1<<N) - 1)<<endl;
}