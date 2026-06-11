#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000009;

int main(){
	int n,k;
	cin >> n >> k;
	vector<ll> x(n);
	for(int i = 0;i < n;i++)cin >> x[i];

	ll ans = 1e15;

	for(int i = 0;i < n;i++){
		if(i + k - 1 < n){
			ll dist = x[i+k-1] - x[i];
			dist += min(abs(x[i+k-1]),abs(x[i]));
			ans = min(ans,dist);
		}
	}

	cout << ans << endl;
}
