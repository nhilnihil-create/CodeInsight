#include <iostream>
using namespace std;
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	long long k=c;
	if (a<b)  swap(a,b);
	if (a<c)  swap(a,c);
	if (b<c)  swap(b,c);
	if (b==k)  cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}