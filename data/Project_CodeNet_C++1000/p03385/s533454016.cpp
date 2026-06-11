#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

int main() {
  string s;
  cin >> s;
  sort(s.begin(),s.end());
  if(s=="abc") cout << "Yes" << endl;
  else cout << "No" << endl;
}