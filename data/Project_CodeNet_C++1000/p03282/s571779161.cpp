#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	cin>>s;
  long long k;cin>>k;
  long long first_non = -1;
  for(long long i=0;i<s.length();i++){
  	if(s[i]-'0'>1){first_non=i;break;}
  }
  if(first_non == -1 || first_non>=k)cout<<1;
  else cout<<s[first_non]-'0';
}