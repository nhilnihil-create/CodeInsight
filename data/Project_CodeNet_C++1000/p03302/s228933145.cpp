#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <regex>
#include <stack>
#include <queue>
#include <vector>
#define MAX_N 100
#define INF 10000000

using namespace std;

string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

long n,a,b;
string s;

void solve(){
	if (a + b == 15) cout << "+" << endl;
	else if (a * b == 15) cout << "*" << endl;
	else cout << "x" << endl;
}

int main() {
	cin >> a>>b;
	solve();
	return 0;
}