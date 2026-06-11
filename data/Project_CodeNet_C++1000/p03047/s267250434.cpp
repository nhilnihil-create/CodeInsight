#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <queue>
#include <deque>
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	cout << n-k+1 << endl;
	return 0;
}
