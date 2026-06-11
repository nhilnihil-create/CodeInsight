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
	int n, h;
	cin >> n >> h;
	vector<int> a(n), b(n);
	priority_queue<int> pq;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		pq.push(b[i]);
	}

	int ans = 0;
	sort(a.begin(), a.end(), greater<int>());
	while (h > 0 && !pq.empty()){
		if (pq.top() < a[0]) break;
		h -= pq.top();
		pq.pop();
		ans++;
	}

	if (h > 0){
		ans += (h+a[0]-1)/a[0];
	}
	cout << ans << endl;
	return 0;
}