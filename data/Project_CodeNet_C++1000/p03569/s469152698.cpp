#include<bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >> s;
  int n,j,i,ans,k;
  bool ha=true;
  n=s.size();
  j=n-1;
  ans=0;
  i=0;
  int med=n/2;
  while(i<=j){
    if(s[i]=='x' && s[j]!='x'){
      ans++;
      i++;
    }else if(s[j]=='x' && s[i]!='x'){
      ans++;
      j--;
    }else if(s[i]!=s[j] && s[i]!='x' && s[j]!='x'){
      ha=false;
      i=j;
    }else if(s[i]==s[j]){
      i++;
      j--;
    }
  }
  if(ha==true){
    cout << ans << endl;
  }else{
    ans=-1;
    cout << ans << endl;
  }
  return 0;

}
