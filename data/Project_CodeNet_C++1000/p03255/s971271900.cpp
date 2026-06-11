#include<iostream>
#include<vector>
#include<algorithm>

const long long INF = (1LL << 63) - 1;

using namespace std;

int main(){
	long long n, x, ans = INF;
	cin >> n >> x;
	vector<long long> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for(int i = 1; i <= n; i++){
		long long cost= 0;
		int p = n;
		cost += (n + i) * x;
		cost += 5 * a[p];
		p -= 2 * i;
		while(p > 0){
			cost += 2 * a[p];
			p -= i;
			if(cost <= 0){
				cost = INF;
				break;
			}
		}
		ans = min(ans, cost);
	}
	cout << ans << endl;
	return 0;
}