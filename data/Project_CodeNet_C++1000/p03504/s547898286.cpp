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
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
using namespace std;

int chan[31][200001];

int main(){
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++){
		int s, t, x;
		cin >> s >> t >> x;
		for (int i = s*2-1; i < t*2; i++){
			chan[x][i] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 200000; i++){
		int sum = 0;
		for (int j = 1; j <= 30; j++){
			sum += chan[j][i];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}