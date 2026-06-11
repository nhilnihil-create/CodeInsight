#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
	int a[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,t=1;
	cin>>n;
	int max1=-1,sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>max1)max1=a[i];
		sum+=a[i];
	}
	if(sum-max1>max1)cout<<"Yes";
	else cout<<"No";
}
