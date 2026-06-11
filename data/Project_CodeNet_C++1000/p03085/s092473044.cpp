#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  string b;
  cin>>b;
  if (b == "A") {
    cout << "T";
  } else if (b == "T") {
    cout << "A";
  } else if (b == "C") {
    cout << "G";
  } else {
    cout << "C";
  }
}
