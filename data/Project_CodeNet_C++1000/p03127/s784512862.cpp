#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  
  int n;
  cin >>n;
  vector<int> list(n);
  rep(i,n ) cin>>list.at(i);
  int ans=list[0];
  rep(i,n-1)ans =gcd(ans,list[i+1]);
  cout<<ans<<endl;
}

