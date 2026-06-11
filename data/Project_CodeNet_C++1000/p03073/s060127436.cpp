#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
  	int mini = s.length();
	//start with 0
  int tot=0;
  for(int i=0;i<s.length();i++){
  	if(i%2==0 && s[i]!='0')tot++;
    if(i%2==1 && s[i]!='1')tot++;
  }
  mini = min(mini,tot);
 tot=0;
  for(int i=0;i<s.length();i++){
  	if(i%2==1 && s[i]!='0')tot++;
    if(i%2==0 && s[i]!='1')tot++;
  }
  mini = min(mini,tot);
  cout<<mini;
}