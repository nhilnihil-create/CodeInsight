#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int c=0;
  int64_t a=0;
  int64_t m=0;
  for(int t=3;a<=n;t++){
    a=0;
    int x=t;
    vector<int> d;
    set<int> p;
    while(x>2){
      d.push_back(x%3*2+3);
      p.insert(x%3);
      x/=3;
    }
    for(int i=d.size()-1;i>=0;i--)
      a=a*10+d.at(i);
    if(p.size()==3&&a<=n&&a>m)
      c++;
    m=max(m,a);
  }
  cout<<c<<endl;
}