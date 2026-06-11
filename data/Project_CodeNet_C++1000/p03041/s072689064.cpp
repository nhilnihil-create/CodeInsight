#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b;
  cin>>b;
  vector<char>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  vec.at(b-1)=vec.at(b-1)-'A'+'a';
  for(ll i=0;i<a;i++){
    cout<<vec.at(i);
  }
  return 0;
}
