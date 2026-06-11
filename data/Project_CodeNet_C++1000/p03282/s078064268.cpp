#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string s;
  ll k;
  cin>>s>>k;
  char c;
  int n=s.size();
  for(ll i=0;i<n;i++){
    if(i==k-1){
      c=s[i];
      break;
    }
    if(s[i]!='1'){
      c=s[i];
      break;
    }
    if(i==n-1) c=s[i];
  }
  cout<<c<<endl;
}
