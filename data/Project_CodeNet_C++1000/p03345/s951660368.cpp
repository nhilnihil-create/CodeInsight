#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18

priority_queue<int,vector<int>,greater<int>> que;


llint a,b,c,k;

void solve(){
	cin >> a >> b >> c >> k;
	if(k%2==0)cout << a-b << endl;
	else cout << b-a << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
