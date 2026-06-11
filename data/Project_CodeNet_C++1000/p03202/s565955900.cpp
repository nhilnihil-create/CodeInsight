//#define DEBUG
#include <cstdio>

using namespace std;

const int maxn=200000, maxa=1000000000;

int min(int a, int b) {
  return a<b ? a : b;
}

bool add(int &n, int num[][2], int size) {
  if (n==0) {
    return false;
  } else if (num[n][1]==size) {
    int t=num[n][0];
    n--;
    if (add(n, num, size)) {
      num[++n][0] = t;
      num[n][1] = 1;
    } else {
      return false;
    }
  } else {
    int t=num[n][1]+1;
    num[n][0]--;
    if (!num[n][0]) {
      n--;
    }
    num[++n][0] = 1;
    num[n][1] = t;
  }
  return true;
}

bool check(int n, int a[], int size) {
  static int str[maxn+1][2];
  int len=0;
  for (int i=1; i<=n; i++) {
    if (a[i]>a[i-1]) {
      if (str[len][1]!=1) {
        str[++len][1] = 1;
        str[len][0] = 0;
      }
      str[len][0] += a[i]-a[i-1];
    } else if (a[i]<=a[i-1]) {
      int off=a[i-1]-a[i];
      for (; off; ) {
        int t=min(off, str[len][0]);
        str[len][0]-=t, off-=t;
        if (!str[len][0]) {
          len--;
        }
      }
      if (!add(len, str, size)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
#ifdef DEBUG
  freopen("src.in", "r", stdin);
  freopen("src.out", "w", stdout);
#endif

  static int a[maxn+1];
  int n;
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    scanf("%d", a+i);
  }

  int ans;
  for (int l=1, r=n, mid; l<=r; ) {
    mid = (l+r)/2;
    if (check(n, a, mid)) {
      r = mid-1;
      ans = mid;
    } else {
      l = mid+1;
    }
  }
  printf("%d", ans);

  fclose(stdin);
  fclose(stdout);
  return 0;
}
