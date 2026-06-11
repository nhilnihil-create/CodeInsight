#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

int prime_count[101];


int main(){
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		int tmp = i;
		for (int j = 2; ; j++){
			while (tmp%j == 0){
				tmp /= j;
				prime_count[j]++;
			}
			if (tmp == 1) break;
		}
	}
	
	int ans = 0;
	
	for (int i = 2; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			for (int k = j+1; k <= n; k++){
				if (prime_count[i] >= 4 && prime_count[j] >= 4 && prime_count[k] >= 2){
					ans++;
				}
				if (prime_count[i] >= 4 && prime_count[j] >= 2 && prime_count[k] >= 4){
					ans++;
				}
				if (prime_count[i] >= 2 && prime_count[j] >= 4 && prime_count[k] >= 4){
					ans++;
				}	
			}
		}
	}

	for (int i = 2; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			if (prime_count[i] >= 14 && prime_count[j] >= 4){
				ans++;
			}
			if (prime_count[i] >= 4 && prime_count[j] >= 14){
				ans++;
			}
			if (prime_count[i] >= 24 && prime_count[j] >= 2){
				ans++;
			}
			if (prime_count[i] >= 14 && prime_count[j] >= 24){
				ans++;
			}
		}
	}

	for (int i = 2; i <= n; i++){
		if (prime_count[i] >= 74) ans++;
	}
	cout << ans << endl;
 	return 0;
 }
