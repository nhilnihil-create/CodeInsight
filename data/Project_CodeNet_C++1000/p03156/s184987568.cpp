#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2) // 2進数の文字列を int に
//cout << fixed << setprecision(15);

int main() {
  int n, a, b;
  cin >> n >> a>> b;
  vi r(3);
  rep(i, n) {
    int p;
    cin >> p;
    if(p <= a) r[0]++;
    else if(p <= b) r[1]++;
    else r[2]++;
  }
  cout << min(r[0], min(r[1], r[2])) << endl;
}
