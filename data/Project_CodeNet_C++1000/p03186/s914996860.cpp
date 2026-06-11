#include <bits/stdc++.h>

using namespace std;

typedef long long tint;

const tint INF = 2e14+1;
const long double PI = 3.141592;
const int MOD =  998244353;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NACHO ios_base::sync_with_stdio(0);cin.tie(NULL);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
 
int main(){
	NACHO;
	int a, b, c; cin >> a >> b >> c;
	int res = min(a+b+1, c);
	cout << res+b << "\n";	
}


 

