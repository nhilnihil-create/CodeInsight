#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	int h,w,n;
	cin >> h >> w >> n;
	int mini[200005];
	for(int i=1;i<=w;i++)
		mini[i-1]=h+1;
	vector<int> wall[200005];
	int cango[200005];
	cango[1-1]=1;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin >> x >> y;
		wall[y-1].push_back(x);
	}
	for(int i=2;i<=w;i++)
	{
		sort(wall[i-1].begin(),wall[i-1].end());
		int count=0;
		cango[i-1]=cango[i-1-1]+1;
		for(int j=1;j<=wall[i-1].size();j++)
		{
//cout << i << ":" << j << ":" << wall[i-1][j-1] << endl;
				int wallx=wall[i-1][j-1];
				if(wallx<=cango[i-1-1])
					continue;
				else if(wallx!=cango[i-1-1]+1+count)
				{
					cango[i-1]=cango[i-1-1]+1+count;
					break;
				}
				cango[i-1]++;
				count++;
		}
	}

	for(int i=1;i<=w;i++)
	{
//		cout << i << ":" << cango[i-1] << endl;
		for(int j=1;j<=wall[i-1].size();j++)
		{
			int wallx=wall[i-1][j-1];
			if(wallx>=cango[i-1])
				mini[i-1]=min(mini[i-1],wallx);
		}
	}
	sort(mini,mini+w);
	cout << mini[0]-1 << endl;

}