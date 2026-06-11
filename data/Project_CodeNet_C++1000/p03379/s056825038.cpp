#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    b.at(i)=a.at(i);
  }
  sort(a.begin(),a.end());
  ll small=a.at(n/2-1);
  ll big=a.at(n/2);
  for(int i=0;i<n;i++){
    if(b.at(i)<=small)
    cout << big << endl;
    else
    cout << small << endl;
  }
}

