#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,q;
  cin>>n>>k>>q;
  vector<int> a(n);
  vector<int> o(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    o.at(i)=a.at(i);
  }
  a.push_back(0);
  sort(o.begin(),o.end());
  int m;
  for(int x=0;x<n;x++){
    vector<vector<int>> c(x+1);
    for(int i=0,p=0;i<=n;i++){
      if(a.at(i)==0){
        sort(c.at(p).begin(),c.at(p).end());
        p++;
      }else
        c.at(p).push_back(a.at(i));
    }
    vector<int> ch;
    for(auto x:c)
      for(int i=0;i<max((int)x.size()-k+1,0);i++)
        ch.push_back(x.at(i));
    if(ch.size()<q)
      break;
    sort(ch.begin(),ch.end());
    m=(x==0?ch.at(q-1)-ch.at(0):min(m,ch.at(q-1)-ch.at(0)));
    for(int i=0;i<n;i++){
      if(a.at(i)==o.at(x)){
        a.at(i)=0;
        break;
      }
    }
  }
  cout<<m<<endl;
}