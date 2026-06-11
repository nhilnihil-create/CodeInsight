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
const int MOD = 1000000007;
int main(){
	int n;
	cin >> n;
	vector<int> d(n);
	for(int i = 0;i < n;i++)cin >> d[i];

	sort(d.begin(),d.end());
	for(int i = 0;i < n;i++){
		if(i % 2 == 0){
			if(d[i] != 0 && d[i] != 12)d[i] = 24 - d[i];
		}
	}

	int ans = 1000000000;
	d.push_back(0);
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n+1;j++){
			ans = min(ans,min(abs(d[i]-d[j]),24-abs(d[i]-d[j])));
		}
	}

	cout << ans << endl;
}
