#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin>>s;
  int k=s.length(),win=0;
  for(int i=0;i<k;i++){
	if(s[i]=='o'){
      win++;
    }
  }
  win+=15-k;
  if(win>=8){
    cout<<"YES\n";
  }
  else{
    cout<<"NO\n";
  }
  return 0;
}
