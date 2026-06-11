#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long llint;
#define inf 1e18

llint r;
void solve(){
	cin >> r;
	string ans;
	if(r<1200)ans="ABC";
	else if(r<2800)ans="ARC";
	else ans="AGC";
	cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
