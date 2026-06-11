#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  set<ll> S;
  for(ll i=0;i<N;i++) {
ll d;
    cin>>d;
    S.insert(d);
  }
  
  cout<<S.size()<<endl;
}
