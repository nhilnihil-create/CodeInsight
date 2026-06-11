#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

typedef long long ll;
const ll INF = (ll)1e18 + 1;

// Grid
ll H, W;

// print(x, y, z);
// printVec(va.begin(), va.end());
void print(){ std::cout << std::endl; }
template <typename Head> void print(Head&& head) { std::cout << head << std::endl; }
template <typename Head, typename... Tail> void print(Head&& head, Tail&&... tail)
{
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...); // or print(tail...);
}

int main(int argc, char* argv[])
{
  ll A, B;
  std::cin >> A >> B;
  A--;
  B--;

  H = 100;
  W = 100;

  // Init
  std::vector< std::string > grid(H, std::string(W, '#'));
  for (ll y = 51; y < H; y++) {
    for (ll x = 0; x < W; x++) {
      grid[y][x] = '.';
    }
  }

  // Put White
  for (ll y = 0; y < 50; y+=2) {
    for (ll x = 0; x < W; x+=2) {
      if (A > 0) {
	grid[y][x] = '.';
	A--;
      }
    }
  }

  // Put Black
  for (ll y = 52; y < H; y+=2) {
    for (ll x = 0; x < W; x+=2) {
      if (B > 0) {
	grid[y][x] = '#';
	B--;
      }
    }
  }

  print(H, W);
  for (ll y = 0; y < H; y++) {
    print(grid[y]);
  }

  return 0;
}
