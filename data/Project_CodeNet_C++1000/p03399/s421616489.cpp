#include<iostream>
using namespace std;
int min(int a,int b)
{
	if(a<=b)
	return a;
	else
	return b;
}
int main()
{
	int A,B,C,D;
	cin>>A>>B>>C>>D;
	cout<<min(A,B)+min(C,D);
	return 0;
} 