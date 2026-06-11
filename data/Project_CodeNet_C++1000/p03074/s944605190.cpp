#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  string s;
  cin>>n>>k>>s;
  s+='#';
  vector<int> v;
  int c=0;
  char h='1';
  for(int i=0;i<n+1;i++){
    if(h!=s.at(i)){
      v.push_back(c);
      h=s.at(i);
      c=0;
    }
    c++;
  }
  if(v.size()%2==0)
    v.push_back(0);
  int a=0;
  for(int i=0;i<k*2+1&&i<v.size();i++)
    a+=v.at(i);
  int m=a;
  for(int i=k*2+2;i<v.size();i+=2){
    a+=v.at(i-1)+v.at(i)-v.at(i-k*2-2)-v.at(i-k*2-1);
    m=max(m,a);
  }
  cout<<m<<endl;
}