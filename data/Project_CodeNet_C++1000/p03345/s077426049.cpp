#include <bits/stdc++.h>
using namespace std;

// a_n- b_n= (S_{n-1}- a_{n-1})- (S_{n-1}- b_{n-1})
//         = -(a_{n-1}- b_{n-1})
//         = (-1)^n (a_0- b_0)
int main(){
  int A0,B0,C0; int64_t K;
  cin >> A0 >> B0 >> C0 >> K;

  int ans= (K%2==0) ? A0- B0
                    : -(A0- B0);
  cout << ans << endl;
}