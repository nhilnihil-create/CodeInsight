#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s[N],a[N];
pair<int ,int >p[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++)cin>>a[i];
		if(n>=m)
	{
		cout<<"0";return 0;
	}
	sort(a,a+m);
	for(int i=1;i<m;i++)
	{
		s[i]=a[i]-a[i-1];
		//cout<<s[i]<<" ";
	}
	sort(s,s+m);
	int sum=a[m-1]-a[0];
	for(int i=m-1;i>=m-n+1;i--)sum-=s[i];
	cout<<sum;
	return 0;
}
