#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w;
	cin>>h>>w;
	int a[10][10];
	for(int i = 0; i<10 ;i++)
		for(int j = 0; j<10; j++)
			cin>>a[i][j];

	for(int k = 0; k<10 ;k++)
		for(int i = 0; i<10; i++)
			for(int j = 0; j<10; j++)
				a[i][j] = min(a[i][j], a[i][k]+a[k][j]);

	int b[h][w];
	for(int i = 0; i<h; i++)
		for(int j= 0 ; j<w; j++)
		{
			cin>>b[i][j];
			if(b[i][j]==-1) b[i][j] = 0;
			else
				b[i][j] = a[b[i][j]][1];
		}
	ll sum = 0;
	for(int i = 0; i<h; i++)
		for(int j =0 ;j<w; j++)
			sum += b[i][j];
	cout<<sum<<endl;
	return 0;
}