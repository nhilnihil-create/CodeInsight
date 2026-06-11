#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sv[100005];

	for(int i=0;i<100005;i++)
		sv[i]=0;
	sv[0]=1;
	sv[1]=1;
	for(int i=2;i<sqrt(100005);i++)
	{
		if(sv[i]==0){
		for(int j=2*i;j<100005;j+=i)
			sv[j]=1;}
	}
	int like[100005];
	for(int i=0;i<100005;i++)
	{
		if(sv[i]==0 && sv[(i+1)/2]==0)
			like[i]=1;
		else
			like[i]=0;
	}
	for(int i=0;i<100005;i++)
		like[i]+= like[i-1];
	int q;
	cin>>q;
	while(q-->0)
	{
		int l,r;
		cin>>l>>r;
		cout<<like[r]-like[l-1]<<"\n";
	}
}