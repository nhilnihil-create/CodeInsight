#include <bits/stdc++.h>
using namespace std;

int V[40];
int C[40];

int main()
{
	int n,x,i,j,y,z;
	cin>>n;
	int ans = 0;
	for(i=0;i<n;i++)
		cin>>V[i];
	for(i=0;i<n;i++)
		cin>>C[i];
	
	for(i=0;i<n;i++){

		ans += max(0,V[i]-C[i]);
	}
	cout<<ans;
}