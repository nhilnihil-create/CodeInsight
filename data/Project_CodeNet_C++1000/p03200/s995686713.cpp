#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){

    string s; cin >> s;
	ll arr[s.length()] = {0};
	if(s[0] == 'B') arr[0] = 1;
	else arr[0] = 0;
	for(ll i = 1; i < s.length(); ++i){
		if(s[i] == 'B'){
			arr[i] = arr[i - 1] + 1;
		}
		else{
			arr[i] = arr[i - 1];
		}
	}
	ll ans = 0;
	for(ll i = 0; i < s.length(); ++i){
		if(s[i] == 'W'){
			ans += arr[i];
		}
	}
	cout << ans;
    return 0;
}
