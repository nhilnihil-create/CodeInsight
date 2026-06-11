#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;

template <class T>
using lim = numeric_limits<T>;

struct sushi{
	int t, d;
	sushi(){t=d=0;}
	sushi(int a, int b){
		t = a;
		d = b;
	}
	
	void show(){
		cout << t << ": " << d << endl; 
	}
};


const int maxn = 1e5;
vector<sushi> leftOvers;
sushi arr[maxn];
int counters[maxn+1];
bool seen[maxn+1];

bool compare(const sushi &a, const sushi &b){
	return a.d > b.d;
}
int main() {
	ios_base::sync_with_stdio(false) ;
	cin.tie(0);
	
	memset(counters, 0, sizeof counters);
	
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++){
		int t,d;
		cin >> t >> d;
		arr[i] = sushi(t,d);
	}
	
	sort(arr, arr+n, compare);
	
	ll total = 0;
	ll unique = 0;
	for (int i = 0; i < k; i++){
		total += arr[i].d;
		if (counters[arr[i].t] == 0) unique++;
		counters[arr[i].t]++;
		seen[arr[i].t] = true;
	}
	
	for (int i = k; i < n; i++){
		if (!seen[arr[i].t]) {
			seen[arr[i].t] = true;
			leftOvers.push_back(arr[i]);
		}
	}
	
	ll ans = total + unique*unique;
	
	int x = 0;
	for (int i = k-1; i >= 0; i--){
		if (x == (int) leftOvers.size()) break;
		if (counters[arr[i].t] == 1) continue;
		
		total -= arr[i].d;
		total += leftOvers[x].d;
		
		counters[arr[i].t]--;
		unique++;
		x++;
		
		ans = max(ans, total+unique*unique);
	}
	

	cout << ans << endl;
}

