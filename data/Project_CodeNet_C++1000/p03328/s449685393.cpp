#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b;
  cin >> a >> b;

  int diff = b - a;
  int ap_sum = diff * (diff + 1) / 2;
  cout << ap_sum - b << "\n";
}
