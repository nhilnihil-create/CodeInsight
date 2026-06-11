#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int A, B, C; cin >> A >> B >> C;
  int mmax = max(max(A, B), C);
  int sum = A+B+C;
  int ans = 0;
//    cout << "mmax" << mmax << endl;
  while ( sum%3 != 0 || sum/3 < mmax ){
    sum += 2;
    ans++;
 //   cout << sum << endl;
  }
  
  cout << ans << endl;
  return 0;
}