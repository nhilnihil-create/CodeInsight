#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
  	int n;
  	cin>>n;
  	string s;
  	cin>>s;
  	int r=0,b=0;
  	for(int i=0;i<s.size();i++){
    	if(s[i]=='B')
          	b++;
      	if(s[i]=='R')
          	r++;
    }
  	if(r>b)
    	cout<<"Yes";
  	else
      	cout<<"No";
	return 0;
}