#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l;
	cin>>l;
	int s=l;
	int n=0;
	int a[61];
	int p=0;
	while(s)
    {
    	a[++n]=s%2;
    	if(a[n]==1) ++p;
    	s/=2;
	}
	cout<<n<<" "<<2*(n-1)+p-1<<endl;
	int now=1;
	int cnt=1;
	for(int i=n-1;i>=1;--i)
	{
		now++;
		cout<<now-1<<" "<<now<<" "<<0<<endl;
		cout<<now-1<<" "<<now<<" "<<cnt<<endl;
		cnt*=2;
		if(a[i]==1) cout<<1<<" "<<now<<" "<<cnt++<<endl;
	}
	return 0;
 } 