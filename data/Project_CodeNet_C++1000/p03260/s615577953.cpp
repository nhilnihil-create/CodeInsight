#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int a,b;
cin >> a >> b;
bool flag=false;

for(int i=1;i<=3;i++)
{
	if((a*b*i)%2!=0)
	{
		flag=true;
		break;

	}
}

if(flag)
{
	cout << "Yes" << endl;
}
else
{
	cout << "No" << endl;
}

 	return 0;
}










