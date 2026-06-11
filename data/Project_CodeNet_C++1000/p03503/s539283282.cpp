#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t;
  cin>>n;
  t=10;
  vector<vector<int>> f(n,vector<int>(t));
  for(int i=0;i<n;i++)
    for(int j=0;j<t;j++)
      cin>>f.at(i).at(j);
  vector<vector<int>> p(n,vector<int>(t+1));
  for(int i=0;i<n;i++)
    for(int j=0;j<=t;j++)
      cin>>p.at(i).at(j);
  int m;
  for(int b=1;b<(1<<t);b++){
    vector<int> c(n,0);
    int x=b;
    for(int i=0;i<t;i++){
      for(int j=0;j<n;j++)
        c.at(j)+=f.at(j).at(i)*x%2;
      x/=2;
    }
    int s=0;
    for(int i=0;i<n;i++)
      s+=p.at(i).at(c.at(i));
    m=(b==1?s:max(m,s));
  }
  cout<<m<<endl;
}