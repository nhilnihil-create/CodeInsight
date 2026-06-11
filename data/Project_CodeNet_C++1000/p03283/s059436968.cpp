#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, M, Q; cin >> N >> M >> Q;

  // int L[M], R[M];
  // for (int i = 0; i < M; i++) {
  //   cin >> L[i] >> R[i];
  // }

  int grid[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      grid[i][j] = 0;
    }
  }

  for (int i = 0; i < M; i++) {
    int l, r; cin >> l >> r;
    grid[l - 1][r - 1]++;
  }

  int p[Q], q[Q];
  for (int i = 0; i < Q; i++) {
    cin >> p[i] >> q[i];
    p[i]--;
  }

  // sort(L, L + M);
  // sort(R, R + M);

  // int left[N + 2]; // Trains that are entirely left of the point
  // int right[N + 2]; // Trains that are entirely right of the point
  // left[0] = 0;
  // right[N + 1] = 0;

  // // The index of the next train to be accounted for in sorted L and R
  // int left_i = 0;
  // int right_i = M - 1;

  // for (int i = 0; i < N + 1; i++) {
  //   int add = 0;
  //   while (left_i < M) {
  //     if (R[left_i] > i + 1) break;
  //     left_i++;
  //     add++;
  //   }
  //   left[i + 1] = left[i] + add;
  // }
  // for (int i = N + 1; i > 0; i--) {
  //   int add = 0; 
  //   while (right_i >= 0) {
  //     if (L[right_i] < i - 1) break;
  //     right_i--;
  //     add++;
  //   }
  //   right[i - 1] = right[i] + add;
  // }

  // for (int i = 0; i < Q; i++) {
  //   cout << right[p[i]] + left[q[i]] - M << endl;
  // }

  // When two numbers are involved, simply making 2 1D cumsums will not work 
  // The results of those cumsums often cannot be combined to obtain the result we want
  // Even if they can be, it is extremely difficult to figure the right combination out

  int table[N + 1][N + 1];
  for (int i = 0; i < N + 1; i++) {
    for (int j = 0; j < N + 1; j++) {
      table[i][j] = 0;
    }
  }
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      table[i][j] = table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1] + grid[i - 1][j - 1];
    }
  }

  for (int i = 0; i < Q; i++) {
    cout << table[q[i]][q[i]] - table[q[i]][p[i]] - table[p[i]][q[i]] + table[p[i]][p[i]] << endl;
  }
}