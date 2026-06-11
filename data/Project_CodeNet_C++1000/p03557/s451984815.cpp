#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int N;
long long a[100000], b[100000], c[100000];

long long upper_search1(long long key) {
  long long r = N;
  long long l = -1;
  while(r - l > 1) {
    long long half = (r + l) / 2;
    if(key < a[half]) r = half;
    else l = half;
  }
  return r;
}

long long upper_search2(long long key) {
  long long r = N;
  long long l = -1;
  while(r - l > 1) {
    long long half = (r + l) / 2;
    if(key < c[half]) r = half;
    else l = half;
  }
  return r;
}
long long lower_search1(long long key) {
  long long r = N;
  long long l = -1;
  while(r - l > 1) {
    long long half = (r + l) / 2;
    if(key <= a[half]) r = half;
    else l = half;
  }
  return r;
}

long long lower_search2(long long key) {
  long long r = N;
  long long l = -1;
  while(r - l > 1) {
    long long half = (r + l) / 2;
    if(key <= c[half]) r = half;
    else l = half;
  }
  return r;
}


int main() {
  cin >> N;
  rep(i, N) {
    cin >> a[i];
  }
  rep(i, N) {
    cin >> b[i];
  }
  rep(i, N) {
    cin >> c[i];
  }

  sort(a, a+N);
  sort(b, b+N);
  sort(c, c+N);

  long long count = 0;

  for(int i = 0; i < N; i++) {
    long long aend = lower_search1(b[i]);
    long long cstart = upper_search2(b[i]);
    count += aend * (N - cstart);
  }

  cout << count << endl;


  return 0;
}