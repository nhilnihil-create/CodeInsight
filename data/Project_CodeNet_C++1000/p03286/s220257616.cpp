#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
string s(int n){
  string ans;
  
  if(n==2){
    ans="110";
    return ans;
  }
  if(n==1){
    ans="1";
    return ans;
  }
  if(n==0){
    ans="0";
    return ans;
  }
  if(n==-1){
    ans="11";
    return ans;
  }
  if(n==-2){
    ans="10";
    return ans;
  }
  
  int b=abs(n%2);
  string c=to_string(b);
  ans=s((n-b)/(-2))+c;
 
  return ans;
}

int main() {
  int n;
  cin >> n;
 
  cout<<s(n)<<endl;
 
}