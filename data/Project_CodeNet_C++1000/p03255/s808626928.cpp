#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long
int sum[200003] , N , X;

signed main(){
	cin >> N >> X; int ans = 1e19;
	for(int i = 1 ; i <= N ; ++i){cin >> sum[i]; sum[i] += sum[i - 1];}
	for(int j = 1 ; j <= N ; ++j){
		int pos = N , all = j * X , cur = 3;
		while(pos > 0){
			all += (cur == 3 ? 5 : cur) * (sum[pos] - sum[max(j , pos) - j]);
			pos = max(pos , j) - j; cur += 2;
		}
		ans = min(ans , all);
	}
	cout << ans + N * X << endl; return 0;
}