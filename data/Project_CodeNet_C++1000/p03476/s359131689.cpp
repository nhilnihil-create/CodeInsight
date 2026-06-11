#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<bool> p(100000,1);
  for(int i=2;i<p.size();i++){
    if(!p.at(i))
      continue;
    for(int j=2;i*j<p.size();j++)
      p.at(i*j)=0;
  }
  vector<bool> sp(100000,0);
  for(int i=3;i<p.size();i++)
    sp.at(i)=(p.at(i)&&p.at((i+1)/2));
  vector<int> c(100001,0);
  for(int i=3;i<p.size();i++)
    c.at(i+1)=c.at(i)+(sp.at(i)?1:0);
  int q;
  cin>>q;
  for(int _=0;_<q;_++){
    int l,r;
    cin>>l>>r;
    cout<<c.at(r+1)-c.at(l)<<endl;
  }
}