#include<iostream>
#include<algorithm>
#include<numeric>

int const num[9] = {1, 7, 4, 5, 3, 2, 9, 6, 8};
int const cnt[9] = {2, 3, 4, 5, 5, 5, 6, 6, 7};
int const MAXN = 10000;

int n[6], c[6], M, N;
bool use[6];
int count[6], ctmp[6], ix[6], maxv;

void search(int nn, int m) {
  if(m == M && nn > 0) return;
  if(nn > 0) {
    for(int i = 0; i*c[m] <= nn; ++i) {
      ctmp[m] = i;
      search(nn - i*c[m], m+1);
    }
    return;
  }
  int res = 0;
  for(int i = 0; i < M; ++i) for(int j = 0; j < ctmp[ix[i]]; ++j) {
    res = res*10 + n[ix[i]];
  }
  if(res > maxv) {
    maxv = res;
    std::copy(ctmp, ctmp+M, count);
  }
}

// try all cases for N <= 35
void calc() { maxv = 0; search(N, 0); }

int main() {
  std::cin >> N >> M;
  std::fill(use, use+6, false);
  std::fill(n, n+6, 0);
  for(int i = 0; i < M; ++i) {
   int a;
   std::cin >> a;
   switch(a) {
     case 1:
       use[0] = true; n[0] = a; break;
     case 7:
       use[1] = true; n[1] = a; break;
     case 4:
       use[2] = true; n[2] = a; break;
     case 2: case 3: case 5:
       use[3] = true; n[3] = std::max(n[3], a); break;
     case 6: case 9:
       use[4] = true; n[4] = std::max(n[4], a); break;
     case 8:
       use[5] = true; n[5] = a;
   }
  }
  // compact n[], c[]
  M = 0;
  for(int i = 0; i < 6; ++i) if(use[i]) {
    n[M] = n[i];
    c[M] = i+2;
    ++M;
  }
  // reminder shoud be LE 6 digits
  int k = 0;
  if(N > (c[0]-1)*6) {
    k = (N - (c[0]-1)*6)/c[0];
    N -= k*c[0];
  }
  std::iota(ix, ix+M, 0);
  std::sort(ix, ix+M, [](int l, int r){ return n[l] > n[r]; });
  calc();
  count[0] += k;
  for(int i = 0; i < M; ++i) {
    char ch = '0' + n[ix[i]];
    for(int j = 0; j < count[ix[i]]; ++j) std::cout << ch;
  }
  std::cout << std::endl;
  return 0;
}
