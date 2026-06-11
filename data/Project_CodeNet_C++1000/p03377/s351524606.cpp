#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A,B,X,Entrou= 0;
	cin>>A>>B>>X;
	
	for(int i = 0; i <= B; i++)
	{
		if(A+i == X){
			cout<<"YES"<<endl;
			Entrou = 1;
		}
	}
	if(Entrou == 0)
	{
		cout<<"NO"<<endl;
	}
	return 0;
}