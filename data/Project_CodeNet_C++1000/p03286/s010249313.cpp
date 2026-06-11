#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007



int main()
{
	FAST;
	ll n;
	cin >> n;
 
    ll b = -2;
    ll f = 2;
 
    string ans = "";
    if (n == 0) {
        ans = "0";
    }
    while (n) {
        int d = (n % b + f)     % f;
        ans += (d + 48);
        n -= d;
        n /= b;
 
    }
 
    reverse(ans.begin(), ans.end());
 
    cout << ans ;
	return 0;
}