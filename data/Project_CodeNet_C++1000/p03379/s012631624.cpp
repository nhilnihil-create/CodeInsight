#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a.at(i);
  }
  b=a;
  sort(b.begin(),b.end());
  ll p,q;
  p=b.at(n/2-1),q=b.at(n/2);
  rep(i,n){
    if(p>=a.at(i)){
      cout << q << endl;
    }else{
      cout << p << endl;
    }
  }
}