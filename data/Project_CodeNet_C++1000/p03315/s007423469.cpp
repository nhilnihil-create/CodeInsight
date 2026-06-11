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
int l = s.length();
int count=0;


for(int i=0;i<l;i++)
{
	if(s[i]=='+')
	{
		count++;
	}
	else
	{
		count--;
	}
}
cout << count << endl;



 	return 0;
}










