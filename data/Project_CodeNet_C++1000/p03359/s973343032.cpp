 
#include<bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int main()
{
	long long n , a , b;
	
	cin >> a >> b;
	
	if( a == b)
	{
		cout << a << endl;
	}
	else if(a < b)
	{
		cout << a ;
	}
	else if( a > b)
	{
		cout << (a -1) << endl;
	}
	
	
return 0;
}


