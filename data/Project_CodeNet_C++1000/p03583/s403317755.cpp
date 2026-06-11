#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  
  if(N%2 == 0) {
    cout << N << " " << N << " " << N/2 << endl;
    return 0;
  }
  if(N == 3) {
    cout << 2 << " " << 2 << " " << 3 << endl;
    return 0;
  }
  
  for(int h=(int)(N/4)+1; h<3501; h++) 
  for(int n=h; n<3501; n++) 
  for(int w=n; w<3501; w++) {
    if(N*(h*n+n*w+w*h) == 4*h*n*w) {
      cout << h << " " << n << " " << w << endl;
      return 0;
    }
  }

}
