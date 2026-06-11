#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[5 + nmax];
std::map<int,int> frec;
void increment(int pos, int lim) {
  frec[pos]++;
  if(0 < pos) {
    if(frec[pos] == lim) {
      frec[pos] = 0;
      increment(pos - 1, lim);
    }
  }
}
int solve(int n, int k) {
  frec.clear();
  
  for(int i = 1;i <= n; i++) {
    if(v[i - 1] < v[i])
      continue;
    else {
      std::map<int,int>::iterator it = frec.lower_bound(v[i] + 1);
      if(k == 1)
        return 0;
      while(it != frec.end())
        frec.erase(it++);
      increment(v[i], k);
    }
    if(0 < frec[0])
      return 0;
  }
  return 1;

}

int binarysearch(int from, int to, int n) {
  
  if(from < to) {
    int mid = (from + to) / 2;
    if(solve(n, mid))
      return binarysearch(from, mid, n);
    else
      return binarysearch(mid + 1, to, n);
  } else
    return from;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++) 
    std::cin >> v[i];
  std::cout << binarysearch(1, n, n);
  return 0;
}
