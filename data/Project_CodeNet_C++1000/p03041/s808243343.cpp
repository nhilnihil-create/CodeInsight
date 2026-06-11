#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,k;
  	cin>>n>>k;
  
  	string s;
  	cin>>s;
  
  	k--;
  if(s[k]=='A'){
  	s[k]='a';
  }
  
  else if(s[k]=='B'){
  	s[k]='b';
  }
  
  else if(s[k]=='C'){
  	s[k]='c';
}
  
  cout<<s<<endl;
}