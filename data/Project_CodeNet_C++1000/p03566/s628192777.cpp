#include <bits/stdc++.h>

using namespace std;

template <class T>
using lim = numeric_limits<T>;

typedef long long ll;
typedef long double ld;

struct hash_pair{
	template <class T1, class T2>
	size_t operator()(const pair<T1,T2>& p)const{
		auto h1 = hash<T1>{}(p.first);
		auto h2 = hash<T2>{}(p.second);
		return h1^h2;
		}
	};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int t[n];
	int v[n];
	int prefixT[n];
	
	int tSum = 0;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		t[i] = temp*2;
		tSum += t[i];
		prefixT[i] = tSum;
		}
		
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		v[i] = temp*2;
		}
		
	int perSec[tSum+1];
	memset(perSec, 0, sizeof(perSec));
	
	for (int i = 0; i < tSum+1; i++){
		perSec[i] = min(i, tSum-i);
		}
	
	int tracker = 0;
	for (int i = 0; i < n; i++){
		for (int j = tracker; j < prefixT[i]+1; j++){
			perSec[j] = min(perSec[j], v[i]);
			}
			tracker += t[i];
		}
		
	for (int i = 0; i < tSum; i++){
		perSec[i+1] = min(perSec[i]+1,perSec[i+1]);
		}
	
	for (int i = tSum; i > 1; i--){
		perSec[i-1] = min(perSec[i]+1, perSec[i-1]);
		}
		
	int total = 0;
	for (int i = 0; i < tSum+1; i++){
		total += perSec[i];
		}
	
	// because we start and end in 0
	// number of ups and number of downs have to be the same
	// the are fills in perfectly
	ld ans = (ld) total / 4;
	cout << fixed << setprecision(6) << ans << endl;
	}
	
	
	
