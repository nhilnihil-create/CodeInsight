#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const ll LLINF = 1e18;


int main(){
	int n;
	cin >> n;
	int nowt = 0, nowx = 0, nowy = 0;
	for (int i = 0; i < n; i++){
		int t, x, y;
		cin >> t >> x >> y;
		int dist = abs(nowx - x) + abs(nowy - y);
		if (dist > t - nowt || dist%2 != (t-nowt)%2){
			cout << "No" << endl;
			return 0;
		}
		nowt = t, nowx = x, nowy = y;
	}
	cout << "Yes" << endl;
	return 0;
}

