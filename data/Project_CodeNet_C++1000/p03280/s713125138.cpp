#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long llint;
#define inf 1e18

llint a,b;
void solve(){
	cin >> a >> b;
	cout << a*b-a-b+1 << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
