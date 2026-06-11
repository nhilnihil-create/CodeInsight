#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int h,w,n;
	cin >> h >> w >> n;
	if(n==0){
		cout << h << endl;
		return 0;
	}
	vector<pair<int,int> > p(n);
	for(int i = 0; i < n; i++){
		// cin >> p[i].first >> p[i].second;
		cin >> p[i].second >> p[i].first;
	}
	// char m[100][100];
	// for(int i = 0; i < 100; i++){
	// 	for(int j = 0; j < 100; j++){
	// 		m[i][j] = 'o';
	// 	}
	// }
	// for(int i = 0; i < n; i++){
	// 	m[p[i].second][p[i].first] = 'x';
	// }

	// for(int i = w; i >=1; i--){
	// 	for(int j = 1; j <= h; j++){
	// 		cout << m[i][j];
	// 	}
	// 	printf("\n");
	// }
	sort(all(p));
	// int ans = h;
	// for(int i = 0; i < n; i++){
	// 	if(p[i].first-1 <= ans && p[i].first > p[i].second){
	// 		ans = p[i].first-1;
	// 		m[p[i].second][p[i].first] = '!';
	// 	}
	// }
	// cout << ans << endl;

	// for(int i = w; i >=1; i--){
	// 	for(int j = 1; j <= h; j++){
	// 		cout << m[i][j];
	// 	}
	// 	printf("\n");
	// }

	int d = 0;
	vector<int> res;
	// int y_now = 0;
	for(int i = 0; i < n; i++){
		// if(p[i].first != y_now) y_now = p[i].first;
		if(p[i].first == p[i].second-d) d++;
		else if(p[i].first<p[i].second-d) res.push_back(p[i].second-1);
	}

	int ans = h;
	for(int i = 0; i < res.size(); i++){
		ans = min(ans,res[i]);
	}
	// if(ans == h) ans++;
	cout << ans << endl;

	return 0;
}