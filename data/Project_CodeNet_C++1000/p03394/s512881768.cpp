#pragma GCC optimize("Ofast")
#pragma comment(linker, "/stack:200000000")
#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define fr first
#define sc second
using namespace std;

const int mnx = 2e6 + 9;
const int mod = 1e9 + 7;
const ll inf = 1e15 + 4;

ll n, a[mnx], k;

void solve(){
	cin >> n;

	if(n == 3){
		cout << "2 5 63\n";
		return;
	}

	if(n == 4){
		cout << "2 3 4 9\n";
		return;
	}

	for(int i = 1; i <= 30000; i++){
		if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0){
			a[++k] = i;
		}
	}

	while(true){
		random_shuffle(a + 1, a + k + 1);

		ll sum = a[1], gcd = a[1];

		for(int i = 2; i <= n; i++){
			sum += a[i];
			gcd = __gcd(gcd, a[i]);
		}

		if(sum % 210 != 0) continue;
		if(gcd != 1) continue;

		for(int i = 1; i <= n; i++){
			cout << a[i] << ' ';
		}
		return;
	}
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
//	srand(time(0));
    int tt = 1;
//    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}

/**

14 8
1 1 1 1 1 4 2 7 3 3 3 3 3 3

6 8
8 2 8 3 6 7
1
5
1 7 6 5 4
**/























