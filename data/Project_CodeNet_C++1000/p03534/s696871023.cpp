#include<bits/stdc++.h>
using namespace std;
int main(){
  char s;
  int a[3]={};
  for(;cin>>s;) a[s-'a']++;
  sort(a,a+3);
  cout<<(a[2]-a[0]<2?"YES":"NO")<<endl;
}