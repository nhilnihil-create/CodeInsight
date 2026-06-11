#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long LL;
using namespace std;

 int main() {

     int N;
     cin >> N;

     vector<int> A(N), B(N), C(N);
     for (int i = 0; i < N; i++) cin >> A[i];
     for (int i = 0; i < N; i++) cin >> B[i];
     for (int i = 0; i < N; i++) cin >> C[i];
     sort(A.begin(), A.end());
     sort(B.begin(), B.end());
     sort(C.begin(), C.end());

     LL ans = 0;

     for (int i = 0; i < N; i++) {
         LL pre = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
         LL over = C.end() - upper_bound(C.begin(), C.end(), B[i]);
         ans += pre * over;
     }


     cout << ans;

     return 0;
 }
