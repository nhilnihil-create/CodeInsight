#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	cin>> n >>k;
	string s;
	cin>> s;
	char c=s[k-1];
	if(c=='A'){
		c = 'a';
	}else if(c=='B'){
		c ='b';
	}else{
		c='c';
	}
	s[k-1] = c;
	cout<< s <<endl;
}
