#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  set<string> w;
  char e=s.at(s.size()-1);
  w.insert(s);
  bool f=1;
  for(int i=1;i<n;i++){
    cin>>s;
    if(e!=s.at(0)||w.count(s))
      f=0;
    e=s.at(s.size()-1);
    w.insert(s);
  }
  cout<<(f?"Yes":"No")<<endl;
}