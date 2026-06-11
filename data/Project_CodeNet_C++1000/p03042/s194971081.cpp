#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n; cin >> n;
  int a,b;
  a = n/100; b = n%100;
  bool M1 = false;  if(a>0 && a<13) M1 = true;
  bool M2 = false;  if(b>0 && b<13) M2 = true;
  if(M1&&M2) cout << "AMBIGUOUS" << endl;
  if((!M1)&&M2) cout << "YYMM" << endl;
  if(M1&&(!M2)) cout << "MMYY" << endl;
  if((!M1)&&(!M2)) cout << "NA" << endl;
}