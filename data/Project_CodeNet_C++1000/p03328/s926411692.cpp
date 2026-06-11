#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;


int main() {
  int a,b;
  cin >> a >> b;
  int p[1000];
  for(int i = 1; i <= 999; i++){
    int h = i * (2 + (i - 1)) / 2;
    p[i] = h;
  } 
  int c = b - a;
  for(int i = 1; i < 999; i++){
    if (p[i + 1] - p[i] == c) cout << p[i] - a << endl;
  } 
	return 0;
}

