#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define debug(x) cerr << #x << " : " << x << "\n"
typedef long long ll;
 
// code //


int main() {
	int n;
	cin >> n;
	cout << (n % 2 == 0 ? n : n*2);
}
