#include <bits/stdc++.h>
using namespace std;
using lint = long long;
typedef pair<int, int> P;
 
int main(){
	int N, M; cin >> N >> M;
	vector<P> vec(M);
	for(int i = 0; i < M; i++) cin >> vec[i].second >> vec[i].first;
	sort(vec.begin(), vec.end());
	int start = 0, ans = 0;
	for(int i = 0; i < M; i++){
		if(start <= vec[i].second) start = vec[i].first, ans++;
	}
	cout << ans << endl;
}