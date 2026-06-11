#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int m; cin>>m;
	for(int n = 11; m > 0 && n <= 55555; n += 5){
		bool flg = true;
		for(int p = 2; p*p <= n; p++){
			if(n%p == 0){
				flg = false;
				break;
			}
		}
		if(flg){
			cout<<n<<" "; m--;
		}
	}

	return 0;
}