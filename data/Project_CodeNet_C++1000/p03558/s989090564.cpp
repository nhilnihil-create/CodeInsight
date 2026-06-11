#include <bits/stdc++.h>
#define ll long long

using namespace std;

int k;
int dist[100010];
queue<int> dial[2];

void update(int cvor, int vrednost, int ind)
{
    cvor=cvor%k;
    if(vrednost<dist[cvor])
        dist[cvor]=vrednost, dial[ind%2].push(cvor);
}

int dijkstra()
{
    int i=1;
    while(true)
    {
        while(dial[i%2].empty())
            i++;
        int tek=dial[i%2].front();
        dial[i%2].pop();
        if(tek==0)
            return dist[tek];
        update(tek+1, dist[tek]+1, i+1);
        update(tek*10, dist[tek], i);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>k;
	for(int i=0;i<k;i++)
        dist[i]=1e7;
    dist[1]=1;
    dial[1].push(1);
    cout<<dijkstra();


	return 0;
}
