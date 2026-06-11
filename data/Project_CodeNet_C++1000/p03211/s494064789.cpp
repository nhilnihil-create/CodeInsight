#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
  int mini = 100000000;
  for(int i=0;i<(int)s.size()-2;i++){
  	int nos=(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0';
    mini = min(mini,abs(nos-753));
  }
  cout<<mini;
}
