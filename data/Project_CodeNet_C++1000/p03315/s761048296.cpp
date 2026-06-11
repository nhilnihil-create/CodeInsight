#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rm(ll n){
    ll ten = 1, ans = 0;
    while(n > 0){
        ll x = n % 10;
        if(x != 0){
            ans += x * ten;
            ten *= 10;
        }
        n /= 10;
    }
    return ans;
}
 
int main()
{
	string s;
	cin>>s;
	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		if (s[i] == '+') ++ans;
		else --ans;
	}
	cout<<ans<<endl;
    return 0;
}