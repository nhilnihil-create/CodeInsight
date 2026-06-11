#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<long long,int> M;
int main()
{
	int N;
	cin>>N;
	long long Sum=0;
	long long Res=0;
	M[Sum]=1;
	while(N--)
	{
		long long A;
		cin>>A;
		Sum+=A;
		Res+=M[Sum];
		M[Sum]++;
	}
	cout<<Res<<endl;
	return 0;
}