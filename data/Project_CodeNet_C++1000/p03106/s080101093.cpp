#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
	int a;cin >> a;
	int b;cin >> b;
	int k;cin >> k;
	int cnt = 0;
	int ans = 0;

	for(int i = min(a,b); i > 0; i--){
		if(a%i == 0 && b%i == 0){
			cnt++;
			if(cnt == k){
				ans = i;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
