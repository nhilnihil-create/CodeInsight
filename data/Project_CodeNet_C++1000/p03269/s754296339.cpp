#include<bits/stdc++.h>
using namespace std;
int l,num=1,m,nl;
int main()
{
	cin>>l;l--;nl=l;
	while(nl)
	{
		if(nl%2==0){nl--;m++;}
		m+=2;nl/=2;num++;
	}
	printf("%d %d\n",num,m);
	while(l)
	{
		if(l%2==0){printf("%d %d %d\n",1,num,l);l--;}
		printf("%d %d %d\n",num-1,num,(l+1)/2);
		printf("%d %d %d\n",num-1,num,0);
		l/=2;num--;
	}
	return 0;
}