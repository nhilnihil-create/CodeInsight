#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int ans=0;
  for(int i=0;i<n;i++){
    int m=0;
    map<char,int>a;
    map<char,int>b;
    for(int j=0;j<i;j++)
      a[s.at(j)]=1;
    for(int j=i;j<n;j++)
      b[s.at(j)]=1;
    for(auto j:a){
      if(j.second==1&&b[j.first]==1)
        m++;
    }
    ans=max(ans,m);
  }
  cout << ans << endl;
  return 0;
}