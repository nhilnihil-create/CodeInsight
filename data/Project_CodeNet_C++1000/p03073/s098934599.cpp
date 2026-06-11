#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int left=0,right=0;
  for(int i=0;i<s.size();i+=2){
    if(s[i]=='0'){
      left++;
    }
    else if(s[i]=='1'){
      right++;
    }
  }
  for(int i=1;i<s.size();i+=2){
    if(s[i]=='1'){
      left++;
    }
    else if(s[i]=='0'){
      right++;
    }
  }
  cout<<min(left,right)<<endl;
}
