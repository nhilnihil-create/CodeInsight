#include <bits/stdc++.h>
using namespace std;
string s;
main () {
	cin>>s;

	if (s[0]=='0' || s[s.size()-1]=='1') { cout<<-1<<endl; return 0; }

	for (int i=0; i<=s.size()-i-2; i++) 
		if (s[i]!=s[s.size()-i-2]) { cout<<-1<<endl; return 0; }

	int cnt=1,last=1;
	for (int i=0; i<s.size()-1; i++) 
		if (s[i]=='1') { cout<<cnt<<" "<<i+2<<endl; cnt=i+2; }
				  else cout<<cnt<<" "<<i+2<<endl;
}