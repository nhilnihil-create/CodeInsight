#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
int n;
cin >> n;
vector<ll> a(n+1);
a.at(0) = 2;
a.at(1) = 1;
for(int i = 2; i <= n;  i++){
  a.at(i) = a.at(i-1) + a.at(i-2);
}
cout << a.at(n) << endl;
}
