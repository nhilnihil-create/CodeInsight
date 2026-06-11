#include<bits/stdc++.h>
using namespace std;
int main(){
  int d,g;
  cin>>d>>g;
  int m=0;
  vector<int> p(d);
  vector<int> c(d);
  for(int i=0;i<d;i++){
    cin>>p.at(i)>>c.at(i);
    m+=p.at(i);
  }
  for(int i=0;i<(1<<d);i++){
    int x=i;
    vector<int> b(d);
    for(int j=0;j<d;j++){
      b.at(j)=x%2;
      x/=2;
    }
    int n=0;
    int s=0;
    for(int j=0;j<d;j++){
      n+=p.at(j)*b.at(j);
      s+=(100*(j+1)*p.at(j)+c.at(j))*b.at(j);
    }
    for(int j=d-1;j>=0&&s<g;j--){
      if(b.at(j))
        continue;
      if(s+100*(j+1)*p.at(j)<=g){
        n+=p.at(j);
        s+=100*(j+1)*p.at(j)+c.at(j);
        continue;
      }
      n+=(g-s+100*(j+1)-1)/(100*(j+1));
      s+=(g-s+100*(j+1)-1)/(100*(j+1))*100*(j+1);
    }
    if(s<g)
      continue;
    m=min(m,n);
  }
  cout<<m<<endl;
}