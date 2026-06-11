#include <bits/stdc++.h>

using namespace std;

typedef long long       ll;

#define all(x)            (x).begin(),(x).end()
#define Sort(x)            sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())

const int MAX1 = 1e6+10,
         Md = 1e9+7,
		 Base = 257;

ll n, bol, root;
string s;

int main(){
    fast_io;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n-1; ++i){
    	if (s[i] != s[n-2-i])	bol = 1;
	}
	if (bol || s[0] == '0' || s[n-1] == '1'){
		cout << -1;
		return 0;
	}
	root = 1;
	for (int i = 0; i < n-1; ++i){
		cout << root << sep << i+2 << '\n';
		if (s[i] == '1')	root = i+2;
	}
    return 0;
}
/*               now or never                 */
