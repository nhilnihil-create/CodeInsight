#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
    int train = 0;
    int bus = 0;
 if(A <= B) { train = A; }
 else { train = B; }

 if(C <= D) { bus = C; }
 else { bus = D; }

 cout << train + bus;
    return 0;
}
