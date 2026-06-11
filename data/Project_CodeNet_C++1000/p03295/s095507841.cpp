#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
const int MOD = 1e9+7;
const int MOOD = 998244353;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

vector<int> graph[100001];

int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > bri(m);
	for (int i = 0; i < m; i++){
		cin >> bri[i].second >> bri[i].first;
	}
	sort(bri.begin(), bri.end());

	int stop = 0, ans = 0; 

	for (int i = 0; i < m; i++){
		if (stop < bri[i].second){
			ans++;
			stop = bri[i].first - 1;
		}
	}
	cout << ans << endl;
	return 0;
}