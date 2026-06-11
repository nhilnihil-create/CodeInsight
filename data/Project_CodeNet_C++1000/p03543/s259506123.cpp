//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
string s;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>s;
	for(ll i=2; i<s.size(); i++)
	{
	    if(s[i]==s[i-1]&&s[i-1]==s[i-2])
	    {
	        cout<<"Yes";
	        return 0;
	    }
	}
	cout<<"No";
	return 0;
}
