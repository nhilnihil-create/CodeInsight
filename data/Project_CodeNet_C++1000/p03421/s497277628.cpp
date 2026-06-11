#include<iostream>
using namespace std;
int N,A,B;
int X[3<<17];
main()
{
	cin>>N>>A>>B;
	for(int i=0;i<=N-A;i++)
	{
		if((N-i+A-1)/A+i==B)
		{
			for(int j=0;j<i;j++)X[N-j-1]=j+1;
			int id=0,t=N;
			while(id*A<N)
			{
				for(int j=A;j--;)
				{
					if(id*A+j<N&&X[id*A+j]==0)X[id*A+j]=t--;
				}
				id++;
			}
			for(int j=0;j<N;j++)cout<<X[j]<<(j==N-1?"\n":" ");
			return 0;
		}
	}
	cout<<-1<<endl;
}