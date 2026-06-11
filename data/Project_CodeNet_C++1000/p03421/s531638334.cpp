#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
int N,A,B;
int main()
{
	int con;
	cin>>N>>A>>B;
	if (B>N-A+1||(ll)A*(ll)B<(ll)N)cout<<-1<<endl;
	else
	{
		for (int i=N-A+1;i<=N;i++)cout<<i<<" ";
		while (1)
		{
			N-=A;
			B--;
			if (!N&&!B)break;
			A=N%B==0?N/B:N/B+1;
			for (int i=N-A+1;i<=N;i++)cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
