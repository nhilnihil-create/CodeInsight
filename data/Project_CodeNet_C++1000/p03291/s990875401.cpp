#include<iostream>
#include<cstdint>
#include<string>

int64_t const MOD = 1e9+7;
std::string s;

int main() {
  std::cin >> s;
  int64_t a = 0, b = 0, c = 0;
  int l = s.size();
  int64_t nq = 1;
  for(int i = 0; i < l; ++i) {
    int64_t na = a, nb = b, nc = c;
    switch(s[i]) {
      case 'A': na += nq; break;
      case 'B': nb += a; break;
      case 'C': nc += b; break;
      default:
        na = a*3+nq;
        nb = b*3+a;
        nc = c*3+b;
        (nq *= 3) %= MOD;
    }
    a = na%MOD; b = nb%MOD; c = nc%MOD;
  }
  std::cout << c << std::endl;
  return 0;
}
