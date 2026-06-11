#include <iostream>
#include <queue>
using namespace std;

bool color[1000];


void bfs(int u)
{
	queue<int> q;
	q.push(u);
	color[u] = 1;
	while(q.front() <= 120)
	{
		int v = q.front();
		q.pop();
		q.push(v + 4);
		color[v+4] = 1;
		q.push(v+7);
		color[v+7] = 1;
	}
}

int main() {
	
	int n;
	cin>>n;
	bfs(0);
	if(color[n])
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	
	return 0;
}