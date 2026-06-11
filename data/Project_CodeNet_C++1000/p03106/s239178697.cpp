#include<bits/stdc++.h>
using namespace std;
#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define ll long long
typedef pair<int, int> P;

int main(){
  int a, b, k;
  int count = 0;
  cin >> a >> b >> k;
  for (int i = min(a, b); i > 0; i--) {
    if (a % i == 0 && b % i == 0) {
      count++;
      if (count == k) {
        cout << i << endl;
        exit(0);
      }
    }

  }
}
