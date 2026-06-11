#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  vector<int> e(n+1,0);
  for(int i=0;i<n;i++)
    e.at(i+1)=e.at(i)+(s.at(i)=='E'?1:0);
  int m=s.size();
  for(int i=0;i<n;i++)
    m=min(m,(i-e.at(i))+(e.at(n)-e.at(i+1)));
  cout<<m<<endl;
}
