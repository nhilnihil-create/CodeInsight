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
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int> > que;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		que.push(x);
	}
	vector<pair<int, int> > vec;
	for (int i = 0; i < m; i++){
		int b, c;
		cin >> b >> c;
		vec.push_back(make_pair(c, b));
	}
	sort(vec.begin(), vec.end(), greater<pair<int, int> >());

	for (int i = 0; i < m; i++){
		for (int j = 0; j < vec[i].second; j++){
			if (que.top() < vec[i].first){
				que.pop();
				que.push(vec[i].first);
			}else{
				i = MOD;
				break;
			}
		}
	}

	ll ans = 0;
	while(!que.empty()){
		ans += que.top();
		que.pop();
	}
	cout << ans << endl;
	return 0;
}