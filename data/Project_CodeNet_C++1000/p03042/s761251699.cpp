#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	cin>>s;
	int ch=0;
	string s1=s.substr(0,2);
	string s2=s.substr(2,2);
	if(s1<="12" && s1>"00" && s2<="12" && s2>"00")
	 cout<<"AMBIGUOUS";
	else if(s1<="12" && s1>"00")
	 cout<<"MMYY";
	else if(s2<="12" && s2>"00")
	 cout<<"YYMM";
	else
	 cout<<"NA";
	return 0;

}