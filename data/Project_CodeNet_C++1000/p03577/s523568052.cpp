#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int main()
{ 
	string a;
	cin>>a;
	a.erase(a.size()-8,8);
	cout<<a<<endl;
	return 0;
}