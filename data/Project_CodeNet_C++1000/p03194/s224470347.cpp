#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;

int main() {
  ll N, P;
  cin >> N >> P;
  ll max=0;
  for (ll i=pow(P,1.0/N)+1; i>=1; i--) {
    if (P % ll(pow(i, N)) == 0) {
      cout << i <<endl; 
      return 0;
    }
  }
        
}