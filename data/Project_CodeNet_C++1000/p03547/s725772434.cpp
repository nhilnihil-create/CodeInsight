#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char ch, h;
	cin>>ch>>h;
	if(ch>h)
		cout<<">";
	else if(ch<h)
		cout<<"<";
	else
		cout<<"=";
	return 0;
}