#include <bits/stdc++.h>
using namespace std;
string s,t;
int main() {
cin>>s>>t;
if(s[0]==t[2] && s[1]==t[1] && s[2]==t[0]) {
	cout<<"YES"<<endl;
} else {
	cout<<"NO"<<endl;
}
}
