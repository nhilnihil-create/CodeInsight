#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll f(ll n) {return n%2?(n+1)/2%2: n/2%2^n;}

int main() {
  ll a,b;
  cin>>a>>b;
  cout<<(f(a-1)^f(b))<<endl;
}