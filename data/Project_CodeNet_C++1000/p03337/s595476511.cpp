#include <bits/stdc++.h>
using namespace std;

int main()
{
	int Soma;
	int Subtrai;
	int Multiplica;
	int A,B;
	
	cin>>A>>B;
	
	Soma = A+B;
	Subtrai = A-B;
	Multiplica= A*B;
	
	if(Soma > Subtrai && Soma > Multiplica){
		cout<<Soma<<endl;
	}
	else
	{
		if(Subtrai > Multiplica){
			cout<<Subtrai<<endl;
		}
		else{
			cout<<Multiplica<<endl;
		}
	}
	
	return 0;
}