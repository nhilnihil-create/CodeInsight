#include <bits/stdc++.h>
using namespace std;
int n , candy , x[200] , ans;
int main(){
	cin >> n >> candy;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i];
	}
	sort(x + 1 , x + n + 1);
	for(int i = 1 ; i <= n ; i++){
		if(candy - x[i] < 0){
			break;
		}
		else{
			candy -= x[i];
			ans++;
		}
	}
	if(candy > 0 && ans == n) cout << ans-1 << endl;
	else cout << ans << endl;
}
// soal B analysis 0