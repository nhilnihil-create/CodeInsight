#include <bits/stdc++.h>

using namespace std;

int vertex[10001];
vector <int> adj[10001];
vector <int> v;
long long int res = 0;
int n,a,b;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<n-1;i++)
    {
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    for(int i=0;i<n;i++)
    {
    	cin >> a;
    	v.push_back(a);
    }

    sort(v.rbegin(),v.rend());

    memset(vertex,-1,sizeof(vertex));

    queue <int> que;
    que.push(1);
    int idx = 0;
    vertex[1] = v[idx++];

    while(!que.empty())
    {
    	int now = que.front();
    	que.pop();

    	for(auto next : adj[now])
    	{
    		if(vertex[next]==-1)
    		{
    			vertex[next] = v[idx++];
    			res += min(vertex[now],vertex[next]);
    			que.push(next);
    		}
    	}
    }

    cout << res << '\n';
    for(int i=1;i<=n;i++)
    {
    	cout << vertex[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}