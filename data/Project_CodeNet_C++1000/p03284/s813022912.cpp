#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long llint;
#define inf 1e18

llint n,k;
void solve(){
	cin >> n >> k;
	llint ans=1;
	if(n%k==0)ans=0;
	cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
