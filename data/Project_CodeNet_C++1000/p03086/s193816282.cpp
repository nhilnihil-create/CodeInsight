#include<bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n,i,ans=0,l=0;
  cin>>s;
  n=s.length();
  for(i=0;i<n;i++){
    if(s.at(i)=='A'||s.at(i)=='T'||s.at(i)=='C'||s.at(i)=='G'){
      l++;
      if(ans<l) ans=l;
    }
    else l=0;
  }
  cout<<ans<<endl;
}