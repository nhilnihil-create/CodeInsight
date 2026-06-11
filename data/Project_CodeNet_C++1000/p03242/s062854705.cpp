#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

string s;
cin >> s;

int l=s.length();

for(int i=0;i<l;i++)
{
	if(s[i]=='9')
	{
		cout << "1";
	}
	else
	{
		cout << "9";
	}
}


 	return 0;
}










