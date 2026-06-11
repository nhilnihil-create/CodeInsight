#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N; 
	int A[262144] = {}; 
	for(int i = 0; i < (1 << N); i++) cin >> A[i]; 
	pair<int, int> first[262144] = {}; 
	pair<int, int> second[262144] = {}; 
	first[0] = make_pair(A[0], 0); 
	for(int bit = 1; bit < (1 << N); bit++){
		vector<pair<int, int>> V; 
		V.emplace_back(A[bit], bit); 
		for(int i = 0; i < N; i++){
			if(!((bit >> i) & 1)) continue; 
			int mask = bit - (1 << i); 
			V.emplace_back(first[mask]); 
			V.emplace_back(second[mask]); 
		}
		sort(V.begin(), V.end(), greater<pair<int, int>>()); 
		unique(V.begin(), V.end()); 
		first[bit] = V.at(0); 
		second[bit] = V.at(1); 
	}
	int mx = 0; 
	for(int i = 1; i < (1 << N); i++){
		mx = max(mx, first[i].first + second[i].first); 
		cout << mx << "\n"; 
	}
}