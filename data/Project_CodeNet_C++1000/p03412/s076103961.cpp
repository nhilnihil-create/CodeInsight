#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef pair<string, int> P;
long long int INF = 1e18;
long long int MOD = 1000000007;

long long int a[210000], b[210000], v[210000];

int main(){
	
	int N;
	cin >> N;
	
	long long int rem = 0, ans = 0;
	
	for(int i = 0; i < N; i++){
		cin >> a[i];
		rem ^= a[i];
	}
	for(int i = 0; i < N; i++){
		cin >> b[i];
		rem ^= b[i];
	}
	
	for(int dig = 1; dig < 30; dig++){
		for(int i = 0; i < N; i++){
			v[i] = a[i] % (1 << dig);
		}
		sort(v, v + N);
		long long int cnt = 0;
		for(int i = 0; i < N; i++){
			long long int num = (1 << dig) - b[i] % (1 << dig);
			cnt += distance(lower_bound(v, v + N, num), v + N);
		}
		cnt %= 2;
		ans += cnt * (1 << dig);
	}
	
	if(N % 2 == 1){
		cout << (ans ^ rem) << endl;
	}else{
		cout << ans << endl;
	}
	
	return 0;
}