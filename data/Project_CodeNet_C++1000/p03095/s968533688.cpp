#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int m=1000000007;
  vector<int>c(26);
  int n;string s;cin>>n>>s;
  for(int i=0;i<26;i++){
    char a='a'+i;
    c.at(i)=count(s.begin(),s.end(),a);
  }
  long long int x=1;
  for(int i=0;i<26;i++){
    x=x*(c.at(i)+1)%m;
  }
  cout<<(x-1)%m<<endl;
}