//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
char c;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	string s="";
	for(ll i=1;i<=3; i++)
	{
	    for(ll j=1; j<=3; j++)
	    {
	        cin>>c;
	        if(i==j)
	        s+=c;
	    }
	}
	cout<<s;
	return 0;
}
