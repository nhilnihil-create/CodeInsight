#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	ll a, b, c; cin >> a >> b >> c;
	cout << min(a+b+1, c)+b << endl;
}