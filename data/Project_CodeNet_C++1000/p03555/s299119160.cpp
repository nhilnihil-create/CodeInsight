#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
    fast;
	string s1,s2;
	cin>>s1>>s2;
	if(s1[0]==s2[2]&&s1[1]==s2[1]&&s1[2]==s2[0])
		cout<<"YES";
	else
		cout<<"NO";
    return 0;
}
