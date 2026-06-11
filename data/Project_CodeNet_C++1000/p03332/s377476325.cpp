#include <bits/stdc++.h>

using namespace std;

	const int MOD = 998244353;
	const int MAXN = 300005;

	int mul (int a, int b){
		return ((long long) a*b) % MOD;
	}
	
	int add (int a, int b){
		a += b;
		if (a >= MOD){
			return (a - MOD);
		}
		return a;
	}

	int rek (int x, int b){
		if (x == 0)return 1;
		if (x == 1)return b;
		
		int aa = rek(x/2, b);
		if (x % 2 == 0){
			return mul(aa,aa);
		} else {
			return mul(mul(aa, aa), b);
		}
	}

	int fak[MAXN];

	int povrh(int n, int k) {
		return mul(fak[n], mul(rek(MOD - 2, fak[k]), rek(MOD - 2, fak[n - k])));
	}

int main (){
	
	fak[0] = 1;
	for (int i = 1; i < MAXN; i++){
		fak[i] = mul(fak[i - 1], i);
	}
	
	int n;
	long long a,b,k;
	cin >> n >> a >> b >> k;
	
	int sol = 0;
	
	for (int i = 0; i <= n; i++){
		long long tren = a*i;
		if (tren > k) break;
		if (((k - tren) % b) == 0){
			long long j = (k - tren) / b;
			if (j > n) continue;
			int curr = mul(povrh(n, i), povrh(n, j));
			//cout << "i je:  " << i << "    j je: " << j << endl;
			//cout << "curr je: " << curr << endl; 			
			sol = add(sol, curr);
		}
	}
	
	cout << sol << "\n";
	
	return 0;
}