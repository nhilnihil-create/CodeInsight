#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b; cin >> n >> a >> b;
    if(a * b < n || n < a + b - 1){
		cout << -1;
		return 0;
    }
    for(int i = n-a+1; i<=n; ++i) cout << i << ' ';
    ll left = n - a;
    for(int i = 1; i < b; ++i){
		ll cur = min(a, left-(b-1-i));
		for(int j=1-cur; j<=0; ++j) cout << left+j << ' ';
		left -= cur;
    }
    return 0;
}
