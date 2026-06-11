#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int cnt;
	for(int i=0; i<s.size(); i++)if(s[i]=='2')cnt++;
	cout<<cnt;
	return 0;
}