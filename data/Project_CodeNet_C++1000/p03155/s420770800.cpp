#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, h, w;
  cin >> n >> h >> w;
  cout << (n - h + 1) * (n - w + 1) << '\n';
}