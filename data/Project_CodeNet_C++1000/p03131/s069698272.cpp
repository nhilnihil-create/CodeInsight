#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
const double pi = 3.141592653589793238;

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


int main() {
  unsigned long long K, A, B;
  cin >> K >> A >> B;

  unsigned long long res = 0;
  if(B <= A+1 || K <= A) { // １円との交換レートが引くもしくは同じ
    cout << K + 1 << endl;
    return 0;
  } else if(K > A){
    res = B + ( (K - (A - 1)) / 2 - 1) * (B-A) + ( (K - (A - 1)) % 2 );
    cout << res << endl;
    return 0;
  }


}

//384626433 + (384626433 - 35897932) * ( (314159265 - (35897932 - 1)) / 2 - 1) + ( (314159265 - (35897932 - 1)) % 2)
