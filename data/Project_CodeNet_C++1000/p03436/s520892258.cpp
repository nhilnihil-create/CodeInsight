#include<bits/stdc++.h>
using namespace std;
#define ll long long
int h,w;
string arr[50];

int main()
{
	cin>>h>>w;
	//memset(marked,0,sizeof(marked));
	for(int i=0;i<h;i++)
		cin>>arr[i];
	vector<int> dist[h*w];
	int d[h*w];
	memset(d, 0,sizeof(d));
	int marked[h*w];
	memset(marked,0,sizeof(marked));
	int c=0;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(arr[i][j]=='.')
		{
				c++;
				if(j<w-1 && arr[i][j+1]=='.')
				{
					dist[i*w+j].push_back(i*w+j+1);
				}
				if(j>0 && arr[i][j-1]=='.')
				{
					dist[i*w+j].push_back(i*w+j-1);
				}
				if(i>0 && arr[i-1][j]=='.')
				{
					dist[i*w+j].push_back((i-1)*w+j);
				}
				if(i<h-1 && arr[i+1][j]=='.')
				{
					dist[i*w+j].push_back((i+1)*w+j);
				}
			}
		}
	}
	queue<int>bfs;
	bfs.push(0);
	//int pl=0;
	while(!bfs.empty())
	{
		int x = bfs.front();
		bfs.pop();
		marked[x]=1;
		
		//pl++;
		for(auto z:dist[x])
		{
			if(marked[z]==0){
				marked[z]=1;
				d[z]=d[x]+1;
				bfs.push(z);
			}
		}

	}
	if(d[(h-1)*w+(w-1)]!=0)
		cout<<c-d[(h-1)*w+(w-1)]-1<<"\n";
	else
		cout<<-1<<"\n";

}
