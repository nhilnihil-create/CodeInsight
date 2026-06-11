#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 1e9 + 7;

int n;

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	if(n == 3){
		cout << "2 5 63";
		return 0;
	}
	else if(n < 21){
		for(int i = 1; i <= (n / 4); i++){
			cout << 12 * (i - 1) + 2 << " " << 12 * (i - 1) + 3 << " " << 12 * (i - 1) + 4 << " " << 12 * (i - 1) + 9 << " ";
		}
		for(int i = 1; i <= (n % 4); i++) cout << ((n / 4) + i) * 12 << " ";
		return 0;
	}
	for(int i = 1; i <= (n / 21); i++){
		for(int j = 1; j <= 30; j++){
			if(j == 15) continue;
			if(!(j % 2) || !(j % 3) || !(j % 5)) cout << (i - 1) * 30 + j << " ";
		}
	}
	for(int i = 1; i <= (n % 21); i++){
		cout << (((n / 21) + i) * 30) << " ";
	}
}

