#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>

#define MAX_N (200000)
#define INF (1000000000)

using namespace std;

// int is_possible(const int *as, int N, int K) {
//   map<int, int> cs;
//   int a_prev = 0;
//   for (int i = 0; i < N; i++) {
//     const int a = as[i];
//     if (a > a_prev) {
//       // 'a's are added to the back of the string.
//       // don't need to do anything.
//     } else {
//       // letter at position a - 1 must be incremented.
//       int j = a - 1, c = ++cs[j];
//       while (c >= K) {
//         if (j > 0) {
//           // increment the letter before
//           c = ++cs[j - 1];
//           cs.erase(j);
//           j--;
//         } else {
//           // impossible
//           return 0;
//         }
//       }
//       // also, letters at position a and beyond are deleted.
//       cs.erase(cs.find(a), cs.end());
//     }
//     a_prev = a;
//   }
//   return 1;
// }

int is_possible(const int *as, int N, int K) {
  int idxs[MAX_N], cnts[MAX_N], tail = 0;
  int a_prev = 0;
  for (int i = 0; i < N; i++) {
    const int a = as[i];
    if (a > a_prev) {
      // 'a's are added to the back of the string.
      // don't need to do anything.
    } else {
      // letters at position a and beyond are deleted.
      tail = lower_bound(idxs, idxs + tail, a) - idxs;
      // letter at position a - 1 must be incremented.
      if (!(tail > 0 && idxs[tail - 1] == a - 1)) {
        // add entry for position a - 1 if it doesn't exist.
        idxs[tail] = a - 1;
        cnts[tail] = 0;
        tail++;
      }
      cnts[tail - 1]++;
      a_prev = a;
      while (cnts[tail - 1] >= K) {
        if (idxs[tail - 1] > 0) {
          // increment the letter before
          if (tail - 1 > 0 && idxs[tail - 2] == idxs[tail - 1] - 1) {
            cnts[tail - 2]++;
            tail--;
          } else {
            idxs[tail - 1]--;
            cnts[tail - 1] = 1;
          }
        } else {
          // impossible
          return 0;
        }
      }
    }
    // printf("i = %d, tail = %d\n", i, tail);
    // for (int j = 0; j < tail; j++) {
    //   printf("j = %d, idxs[j] = %d, cnts[j] = %d\n", j, idxs[j], cnts[j]);
    // }
    a_prev = a;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  // read inputs
  int N, as[MAX_N];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &as[i]);
  }

  // solve binary search
  int le = 0, ri = N;
  while (ri - le > 1) {
    const int m = (le + ri) / 2;
    if (is_possible(as, N, m)) {
      ri = m;
    } else {
      le = m;
    }
  }
  printf("%d\n", ri);

  return 0;
}
