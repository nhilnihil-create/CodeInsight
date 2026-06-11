#include<bits/stdc++.h>

#define SORT(v) sort(v.begin(),v.end())
#define si(n) scanf("%d",&n)
#define sii(n,m) scanf("%d %d",&n,&m)
#define sl(n) scanf("%lld",&n)
#define sll(n,m) scanf("%lld %lld",&n,&m)
#define ss(cad) scanf("%s",cad)
#define PB push_back
#define fst first
#define scn second
#define DBG(x) cerr << #x << " = " << (x) << endl; 
#define M 1000000007
#define N_MAX 100010

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vp;

int main()
{
	int n;
	si(n);
	vector<vi> gr(n);  // {arista, peso}
	for(int i = 1; i < n; i++)
	{
		gr[i].push_back((i*10)%n);
		gr[i].push_back((i+1)%n);
	}

	vb visit(n);
	deque<pi> cola;
	cola.push_back({1, 1});

	while(!cola.empty())
	{
		pi curr = cola.front();
		cola.pop_front();
		if(visit[curr.fst])
			continue;
		//cout << curr.fst << endl;
		visit[curr.fst] = 1;
		if(curr.fst == 0)
		{
			printf("%d\n", curr.scn);
			return 0;
		}
		if(visit[gr[curr.fst][0]] == false)
			cola.push_front({gr[curr.fst][0], curr.scn});

		if(visit[gr[curr.fst][1]] == false)
			cola.push_back({gr[curr.fst][1], curr.scn+1});
	}

    return 0;
}
