#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
#include <functional>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 10000


int main() {
  int A, B, K;

  cin >> A >> B >> K;

  for (int i = 0; i < K; i++) {
    A = A / 2 * 2;
    B += A / 2;
    A -= A / 2;

    swap(A, B);
  }

  if (K % 2) swap(A, B);

  cout << A << " " << B << endl;

  return 0;
}
