#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,q;
  cin >> n>>q;
  string s;
  cin >> s;
  vector<ll> a(q),b(q);
  rep(i,q){
    cin>>a.at(i)>>b.at(i);
  }
  vector<ll> rui(n+1,0);
  for(ll i=1;i<s.size();i++){
    if(s.at(i-1)=='A' &&s.at(i)=='C'){
      rui.at(i+1)=rui.at(i)+1;
    }else{
      rui.at(i+1)=rui.at(i);
    }
  }
  rep(i,q){
    cout << rui.at(b.at(i))-rui.at(a.at(i))<<endl;
  }
}
 