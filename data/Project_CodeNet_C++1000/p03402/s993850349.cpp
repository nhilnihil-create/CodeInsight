#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<ll> dqll;

#define MOD 1000000007

int main() {
  ll A, B;
  cin >> A >> B;
  A--;
  B--;

  puts("100 100");
  for (int i = 1; i <= 100; i++) {
    //printf("%d ", i);
    for (int j = 1; j <= 100; j++) {
      if (i % 2 == 1) {
        if (j <= 50)
          printf(".");
        else
          printf("#");
      } else {
        if(j <= 50 ){
          if (j <= 48 && j % 2 == 0 && B > 0) {
            printf("#");
            B--;
          } else {
            printf(".");
          }
        } else {
          if (j <= 98 && j % 2 == 0 && A > 0) {
            printf(".");
            A--;
          } else {
            printf("#");
          }
        }
      }
    }  // j
    printf("\n");
  }  // i

  return 0;
}
