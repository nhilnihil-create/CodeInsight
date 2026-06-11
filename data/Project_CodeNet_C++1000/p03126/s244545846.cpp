#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> pref(M, 0);
	for(int i=0; i<N; ++i){
		int K;
		cin >> K;
		for(int j=0; j<K; ++j){
			int A;
			cin >> A;
			++pref[A-1];
		}
	}
	int ans = 0;
	for(int i=0; i<M; ++i){
		if(pref[i]==N) ++ans;
	}
	cout << ans << endl;
}