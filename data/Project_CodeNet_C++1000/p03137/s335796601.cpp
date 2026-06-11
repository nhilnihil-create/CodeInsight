#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int>a(m);
  for(int i=0;i<m;i++)
    cin >> a.at(i);
  sort(a.begin(),a.end());
  vector<int>d(m-1);
  for(int i=0;i<m-1;i++)
    d.at(i)=a.at(i+1)-a.at(i);
  int ans=0,mem=0,ka=0;
  sort(d.begin(),d.end(),greater());
  for(int i=0;i<n-1&&i<d.size();i++){
    ans+=d.at(i);
  }
  ans=a.at(m-1)-a.at(0)-ans;
  cout << ans << endl;
  return 0;
}