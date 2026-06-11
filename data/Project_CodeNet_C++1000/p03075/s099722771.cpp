#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
vector<int> x(5);
rep(i,5) cin >> x.at(i);
int k;
cin >> k;
bool ans = false;
rep(i,5)rep(j,i)if(abs(x.at(i)-x.at(j)) > k) ans = true;

puts(!ans?"Yay!":":(");
}
  
