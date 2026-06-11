#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  string s;
  cin>>s;
  int a[3]={};
  for(int i=0;i<s.size();i++){
    a[s[i]-'a']++;
  }
  int c=min({a[0],a[1],a[2]});
  r(i,3)a[i]-=c;
  sort(a,a+3);
  if(a[2]>1||a[1]>1)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}