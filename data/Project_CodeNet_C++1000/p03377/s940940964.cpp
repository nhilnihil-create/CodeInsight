#include<iostream>
#include<algorithm>
using namespace std ;
int main()
{
	int A,B,X;
	cin>>A>>B>>X;
	if(A==X)
	{
		cout<<"YES";
		return 0;
	}
	else if (A>X)
	{
		cout<<"NO";
		return 0; 
	}
	else 
	{
		if(A+B>=X)
		{
			cout<<"YES";
			return 0;
		}
		else 
			cout<<"NO";
	}

	return 0;
}