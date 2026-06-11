#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
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
const int MOD = 1000000007;
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	
	for(int i = 0;i < n;i++)cin >> a[i];

	if(a[0] != 0){
		cout << -1 << endl;
		return 0;
	}

	for(int i = 0;i < n-1;i++){
		if(a[i+1] > a[i] + 1){
			cout << -1 << endl;
			return 0;
		}
	}

	ll ans = 0;
	for(int i = 0;i < n;i++){
		int now = a[i];
		int j = i;
		while(j + 1 < n && a[j+1] > a[j]){
			j++;
		}
		ans += a[j];
		i = j;
	}

	cout << ans << endl;
}
