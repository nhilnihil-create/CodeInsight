#include<iostream>
#include<bitset>
using namespace std;
const int N=4e6+10;
bitset<N>s;
int n;
int main()
{
	cin>>n;
	int x,res=0;
	s[0]=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		res+=x;
		s|=s<<x;
	}
	for(int i=(res+1)/2;;i++)
	if(s[i])
	{
		printf("%d\n",i);
		break;
	}
} 