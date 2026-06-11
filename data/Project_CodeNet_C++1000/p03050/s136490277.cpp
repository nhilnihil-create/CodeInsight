#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long N;
main()
{
	cin>>N;
	vector<long>d;
	for(long i=1;i*i<=N;i++)
	{
		if(N%i==0)
		{
			d.push_back(i);
			if(N/i!=i)d.push_back(N/i);
		}
	}
	long ans=0;
	for(int i=0;i<d.size();i++)
	{
		long M=d[i];
		if(M==1)continue;
		M--;
		if(N/M==N%M)ans+=M;
	}
	cout<<ans<<endl;
}
