#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

# define REP(i,n) for(int i=0; i<n; i++)

using namespace std;

int main(){
	
	long long int n, c, xi, vi, x, v, ans;
	vector<pair<long long int, long long int> > sushi;
	long long int v_t1[100005], v_t2[100005];
	long long int g[100005][2];
	
	cin >> n >> c;
	
	sushi.push_back(make_pair(0,0));
	REP(i,n){
		cin >> xi >> vi;
		sushi.push_back(make_pair(xi,vi));
	}
	
	v_t1[0] = 0;
	v_t2[0] = 0;
	
	for(int i=1; i<=n; i++){
		v_t1[i] = v_t1[i-1] + sushi[i].second;
		v_t2[i] = v_t2[i-1] + sushi[n-(i-1)].second;
	}
	
	g[0][0] = 0;
	g[0][1] = 0;
	for(int i=1; i<=n; i++){
		g[i][0] = max(g[i-1][0], v_t1[i]-sushi[i].first);
		g[i][1] = max(g[i-1][1], v_t1[i]-2*sushi[i].first);
	}
	// g[i][0] : v1+v2+...+vk - xk (0<=k<=i) が最も大きくなるkの、v1+v2+...+vk - xk の値
	// g[i][1] : v1+v2+...+vk - 2*xk (0<=k<=i) が最も大きくなるkの、v1+v2+...+vk - 2*xk の値
	
	ans = 0;
	
	for(int i=1; i<=n; i++){
		// 入店した位置からsushi[i]まで時計回りに歩く
		x = sushi[i].first;
		v = v_t1[i];
		ans = max(ans, v-x);
		
		// 入店した位置からsushi[i]まで反時計回りに歩く
		x = c - sushi[i].first;
		v = v_t2[n-(i-1)];
		ans = max(ans, v-x);
	}
	
	
	for(int i=1; i<=n; i++){
		x = 2*(c-sushi[i].first);
		v = v_t2[n-(i-1)];
		ans = max(ans, g[i-1][0] + v-x);
		
		x = c-sushi[i].first;
		ans = max(ans, g[i-1][1] + v-x);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
