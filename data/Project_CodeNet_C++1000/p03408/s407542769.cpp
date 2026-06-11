#include<bits/stdc++.h>
using namespace std;
int main(){
  map<string,int> p;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    p[s]++;
  }
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    string t;
    cin>>t;
    p[t]--;
  }
  int a=0;
  for(auto x:p)
    a=max(a,x.second);
  cout<<a<<endl;
}