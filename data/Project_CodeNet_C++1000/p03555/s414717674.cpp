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
	string s,t;
	cin>>s>>t;
	reverse(t.begin(),t.end());
	if(s==t)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}