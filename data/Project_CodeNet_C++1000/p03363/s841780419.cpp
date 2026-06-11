#include <bits/stdc++.h>
using namespace std;
long long n , x[300000] , previx[300000] , ans;
map<long long , int>pos; 
int main(){
	cin >> n;
	pos[0]++;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i];
		previx[i] = x[i] + previx[i - 1];
		pos[previx[i]]++;
		if(pos[previx[i]] > 1){
			ans += pos[previx[i]] - 1;
		}
	}
	cout << ans << endl;
}