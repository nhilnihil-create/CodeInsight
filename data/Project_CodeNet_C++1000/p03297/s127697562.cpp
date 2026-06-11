#include<iostream>
#include<algorithm>
#include<cstdint>

int64_t gcd(int64_t a, int64_t b) {
  int64_t r = a%b;
  while(r){ a=b; b=r; r=a%b; }
  return b;
}

int64_t floor_div(int64_t x, int64_t y) {
  int64_t res = x/y, rem = x%y; // res*y+rem == x and abs(rem)<abs(y) by spec
  if(rem!=0 && (rem < 0) != (y < 0)) --res;
  return res;
}

bool solve() {
  int64_t A, B, C, D; std::cin >> A >> B >> C >> D;
  if(A < B) return false;
  if(D < B) return false;
  if(C-B+1 >= 0) return true;
  int64_t q = gcd(D, B);
  int64_t r = A%q;
  // min next morning:
  int64_t x = floor_div(C-r, q) + 1;
  return q*x+r >= B;
}

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int T; std::cin >> T;
  for(int i = 0; i < T; ++i) std::cout << (solve()? "Yes\n": "No\n");
  return 0;
}
