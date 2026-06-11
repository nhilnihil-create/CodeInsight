#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  if(s[0]=='a' && s[1] =='b' && s[2] == 'c'){
    cout<<"Yes"<<'\n';
  }
  else if(s[0] == 'a' && s[1] == 'c' && s[2] == 'b'){
    cout<<"Yes"<<'\n';
  }
  else if(s[0] == 'b' && s[1] == 'a' && s[2] == 'c'){
    cout<<"Yes"<<'\n';
  }
  else if(s[0] == 'b' && s[1] == 'c' && s[2] == 'a'){
    cout<<"Yes"<<'\n';
  }
  else if(s[0] == 'c' && s[1] == 'a' && s[2] == 'b'){
    cout<<"Yes"<<'\n';
  }
  else if(s[0] == 'c' && s[1] == 'b' && s[2] == 'a'){
    cout<<"Yes"<<'\n';
  }
  else {
    cout<<"No"<<'\n';
  }
  return 0;
}
