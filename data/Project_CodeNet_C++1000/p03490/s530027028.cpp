#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define MAX_LEN (8000)

// dp table
int dpx[MAX_LEN + 1][2 * MAX_LEN + 1], dpy[MAX_LEN + 1][2 * MAX_LEN + 1];

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  char insts[MAX_LEN + 1];
  int x, y;
  scanf("%s", insts);
  scanf("%d %d", &x, &y);
  const int len = strlen(insts);

  // create list of distances to move along each axis
  int cnt = 0, dx_init, dir = 0;
  vector<int> dxs, dys;
  for (int i = 0; i < len; i++) {
    const char inst = insts[i];
    if (inst == 'F') {
      cnt++;
    } else {
      if (dir == 0) {
        if (dys.size() == 0) {
          dx_init = cnt;
        } else {
          dxs.push_back(cnt);
        }
      } else {
        dys.push_back(cnt);
      }
      cnt = 0;
      dir = !dir;
    }
  }
  // record last
  if (dir == 0) {
    if (dys.size() == 0) {
      dx_init = cnt;
    } else {
      dxs.push_back(cnt);
    }
  } else {
    dys.push_back(cnt);
  }

  // printf("dx_init = %d\n", dx_init);
  // printf("dxs = ");
  // for (int dx : dxs) {
  //   printf("%d ", dx);
  // }
  // printf("\n");
  // printf("dys = ");
  // for (int dy : dys) {
  //   printf("%d ", dy);
  // }
  // printf("\n");

  // solve dp for x
  for (int j = 0; j < 2 * len + 1; j++) {
    dpx[0][j] = 0;
  }
  dpx[0][dx_init + len] = 1;
  for (int i = 0, i_end = dxs.size(); i < i_end; i++) {
    const int dx = dxs[i];
    for (int j = 0; j < 2 * len + 1; j++) {
      dpx[i + 1][j] = (j - dx >= 0 ? dpx[i][j - dx] : 0) ||
                      (j + dx < 2 * len + 1 ? dpx[i][j + dx] : 0);
    }
  }
  // for (int j = 0; j < 2 * len + 1; j++) {
  //   printf("%d ", dpx[dxs.size()][j]);
  // }
  // printf("\n");

  // solve dp for y
  for (int j = 0; j < 2 * len + 1; j++) {
    dpy[0][j] = 0;
  }
  dpy[0][len] = 1;
  for (int i = 0, i_end = dys.size(); i < i_end; i++) {
    const int dy = dys[i];
    for (int j = 0; j < 2 * len + 1; j++) {
      dpy[i + 1][j] = (j - dy >= 0 ? dpy[i][j - dy] : 0) ||
                      (j + dy < 2 * len + 1 ? dpy[i][j + dy] : 0);
    }
  }
  // for (int j = 0; j < 2 * len + 1; j++) {
  //   printf("%d ", dpy[dys.size()][j]);
  // }
  // printf("\n");

  if (dpx[dxs.size()][x + len] && dpy[dys.size()][y + len]) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
