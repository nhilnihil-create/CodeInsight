#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
typedef pair<P, P> P2;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int DP[110000] = {};

int main(){
	
	int N;
	cin >> N;
	
	P2 A[1100];
	for(int i = 0; i < N; i++){
		cin >> A[i].second.first >> A[i].first.second >> A[i].second.second;
		A[i].first.first = A[i].second.first + A[i].first.second;
	}
	
	sort(A, A + N);
	
	for(int i = 0; i < N; i++){
		int w = A[i].second.first;
		int s = A[i].first.second;
		long long int v = A[i].second.second;
		for(int j = s; j >= 0; j--){
			DP[j + w] = max(DP[j + w], DP[j] + v);
		}
	}
	
	long long int ans = 0;
	
	for(int i = 0; i < 100000; i++){
		ans = max(ans, DP[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
