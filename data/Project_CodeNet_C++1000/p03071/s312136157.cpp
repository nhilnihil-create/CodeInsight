#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a>>b;
  vector<ll>vec(4);
  vec.at(0)=a;
  vec.at(1)=b;
  vec.at(2)=a-1;
  vec.at(3)=b-1;
  sort(vec.begin(),vec.end());
  cout<<vec.at(3)+vec.at(2)<<endl;
  return 0;
  
}
