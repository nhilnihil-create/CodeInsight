//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
string s1,s2;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>s1>>s2;
	reverse(s1.begin(),s1.end());
	if(s1==s2)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
