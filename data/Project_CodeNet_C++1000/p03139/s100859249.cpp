#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int N,A,B,sum;
	cin>>N>>A>>B;
	sum=A+B;
	if(A==N&&B==N)
		sum=N;
	else if(sum>=N)
		sum-=N;
	else
		sum=0;
	cout<<min(A,B)<<" "<<sum<<endl;
	return 0;
}
