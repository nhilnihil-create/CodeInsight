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

priority_queue<llint,vector<llint>,greater<llint>> que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int n;
string s;

void solve(){
	cin >> n;
	if(n==25)cout << "Christmas";
	if(n==24)cout << "Christmas Eve";
	if(n==23)cout << "Christmas Eve Eve";
	if(n==22)cout << "Christmas Eve Eve Eve";
	cout << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
