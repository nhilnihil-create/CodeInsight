#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
priority_queue<long long>q;
int main(){
	int n,t=0;
	long long sa=0,sb=0;
	long long now;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],sa+=a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i],sb+=b[i];
	if(sa<sb)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<b[i])
		now+=a[i]-b[i],t++;
		else
		q.push(a[i]-b[i]);
	}
	while(!q.empty()){
		long long tmp=q.top();
		q.pop();
		if(now<0)
		{
			now+=tmp;
			t++;
		}
		else
		break;
	}
	cout<<t;
}