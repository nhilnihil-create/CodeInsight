#include<iostream>
using namespace std;
int main()
{
	int K,m=0,n=0;
	cin>>K;
	for(int i=1;i<=K;i++){
		if(i%2!=0)
		m++;
		else
		n++;
	}
	cout<<n*m<<endl;
	return 0;
}