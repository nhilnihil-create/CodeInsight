#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	int a,p, pies;
	cin >> a >> p;
	p = a * 3 + p ;
	if(p % 2 == 0)
		pies = p/2;
	else
		pies = (p-1)/2;
	cout << pies;
	
	
}	
