#include <bits/stdc++.h>
using namespace std;

int Soma(int N)
{
	
	int J = N;
	while(true)
	{
		
	
		if( J % 2 == 0 && J % N == 0 ){
			return J;
		}
			J = J+N;
	}
}
int main()
{
	int N;
	
	cin>>N;
	cout<<Soma(N)<<endl;
	
	
}