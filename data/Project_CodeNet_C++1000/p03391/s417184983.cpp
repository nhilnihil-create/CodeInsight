#include<iostream>
using namespace std;
int N;
long ans,A,B,M=2e9;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>A>>B;
		ans+=A;
		if(A>B&&M>B)M=B;
	}
	cout<<(M>1e9?0:ans-M)<<endl;
}