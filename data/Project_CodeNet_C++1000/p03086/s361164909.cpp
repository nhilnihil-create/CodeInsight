#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  string a;
  cin>>a;
  ll b=a.size();
  vector<ll>vec(b);
  for(ll i=0;i<b;i++){
    for(ll j=i;j<b;j++){
      if(a.at(j)!='A'&&a.at(j)!='T'&&a.at(j)!='C'&&a.at(j)!='G'){
        break;
      }
      vec.at(i)+=1;
    }
  }
  sort(vec.begin(),vec.end());
  cout<<vec.at(b-1)<<endl;
    
  return 0;
}
