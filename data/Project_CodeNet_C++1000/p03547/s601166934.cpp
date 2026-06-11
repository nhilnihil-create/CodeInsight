#include<bits/stdc++.h>
using namespace std;

int hexa(char a)
{
	switch(a)
	{
	case 'A':
		return 10;
	case 'B':	
		return 11;
	case 'C': 
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;				
	}	
}



int main()
{
	char a,b;
	cin>>a>>b;
	
	int an,bn;
	an=hexa(a);
	bn=hexa(b);
	
	if(an<bn)
		cout<<"<";
	else
		{
			if(an>bn)
			cout<<">";
			else{
			
			cout<<"=";
		}}

	return 0;
}