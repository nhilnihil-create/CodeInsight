#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int a[3]={0,0,0};
  for(int i=0;i<s.size();i++){
    int q=s[i]-'a';
    a[q]++;
  }
  int m=abs(a[0]-a[1]);
  m=max(abs(a[1]-a[2]),m);
  m=max(abs(a[0]-a[2]),m);
  if(m<=1)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}