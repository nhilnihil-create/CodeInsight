#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define inside sl<=l&&r<=sr
#define outside r<sl||sr<l
#define INF 1000000009
#define mod 1000000007
using namespace std;
typedef long long ll;
int n;
struct block{
	ll w, s, v;
};
block arr[1003];

int com(const block& a, const block& b){
	return a.w+a.s < b.w+b.s;
}

ll dp[1003][20004];

int main(){
	//freopen("stl.gir", "r", stdin);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i].w >> arr[i].s >> arr[i].v;
	}
	
	sort(arr, arr+n, com);
	
	/*for (int i = 0; i < n; i++){
		cout << "(" << arr[i].w << ", " << arr[i].s << ", " << arr[i].v << ")\n";
	}*/
	
	// dp[i][j] = ilk i blok kullanılarak toplam ağırlığı j olan max value
	// dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 20004; j++){
			if (i == 0){
				if (j < arr[i].w) dp[i][j] = 0;
				else dp[i][j] = arr[i].v;
			} else if (j == 0){
				dp[i][j] = 0;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if (j-arr[i].w >= 0 && arr[i].s >= j-arr[i].w) dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i].w]+arr[i].v);
			}
		}
	}
	
	//cout << dp[1][0] << endl;
	cout << dp[n-1][20003] << endl;
	
}