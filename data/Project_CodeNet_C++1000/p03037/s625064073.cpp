#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int>a(m);
  vector<int>b(m);
  for(int i=0;i<m;i++)
    cin >> a.at(i) >> b.at(i);
  sort(a.begin(),a.end(),greater());
  sort(b.begin(),b.end());
  cout << max(0,b.at(0)-a.at(0)+1) << endl;
  return 0;
}