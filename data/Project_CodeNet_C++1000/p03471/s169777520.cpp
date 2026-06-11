#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
ll N, Y, arr[3];


void solve() {
  ll x, y, Nmx;
  for(x = 0; x <= N; x++) {
    Nmx = N - x;
    for(y = 0; y <= Nmx; y++) {
      if(9000*x + 4000*y + 1000*N == Y) { // 10000*x + 5000*y + 1000*(N-x-y) == Y
	arr[0] = x, arr[1] = y, arr[2] = Nmx - y;
	return;
      }
    }
  }
}

int main() {
  cin >> N >> Y;
  memset(arr, -1, sizeof(arr));
  solve();
  cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
}
