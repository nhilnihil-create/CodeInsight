#include<bits/stdc++.h>
using namespace std;
int A[10010],B[10010];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<N;i++)
		cin>>B[i];
	long long Asum=0,Bsum=0,Csum=0;
	for(int i=0;i<N;i++)
	{
		Asum+=A[i];
		Bsum+=B[i];
		Csum+=max(0,(B[i]-A[i]+1)/2);
	}
	Bsum-=Asum;
	if(Bsum<0)
		puts("No");
	else if(Bsum==0)
	{
		bool ok=true;
		for(int i=0;i<N;i++)
			if(A[i]!=B[i])
				ok=false;
		if(ok)
			puts("Yes");
		else	puts("No");
	}
	else
	{
		if(Csum>Bsum)
			puts("No");
		else	puts("Yes");
	}
	return 0;
}
