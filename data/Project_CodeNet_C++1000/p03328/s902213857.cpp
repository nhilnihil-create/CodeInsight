#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll a,b,n;
  cin >> a >> b;
  n = b-a;
  cout << n*(n+1)/2-b << endl;
}