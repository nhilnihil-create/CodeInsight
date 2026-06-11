#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[10];
int main() {
	string s;
	cin>>s;
	if(s.size()==2)cout<<s<<endl;
	else{
		cout<<s[2]<<s[1]<<s[0]<<endl;
	}
	return 0;
}