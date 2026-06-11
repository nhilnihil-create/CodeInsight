#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	vector <int> a(N);
	for (auto &i : a) cin >> i;
	bool allpos = false;
	int small = *min_element(a.begin(),a.end()), big = *max_element(a.begin(),a.end());
	int smallid = min_element(a.begin(),a.end()) - a.begin();
	int bigid = max_element(a.begin(),a.end()) - a.begin();
//	cout << small << " " << smallid << "\n";
//	cout << big << " " << bigid << "\n";
	queue <pair<int,int>> moves;
	if (!(big < 0 || small >= 0)){
		if (abs(big) >= abs(small)){
			for (int i = 0; i < N; ++i){
				if (a[i] < 0){
					moves.push(make_pair(bigid, i));
					a[i] += big;
				}
			}
			allpos = true;
		}else{
			for (int i = 0; i < N; ++i){
				if (a[i] > 0){
					moves.push(make_pair(smallid, i));
					a[i] += small;
				}
			}
			allpos = false;
		}
	}else if(small >= 0){
		allpos = true;
	}
	if (allpos){
		for (int i = 1; i < N; ++i){
			if (a[i-1] > a[i]){
				moves.push(make_pair(i-1, i));
				a[i] += a[i-1];
			}
		}
	}else{
		for (int i = N-2; i >= 0; --i){
			if (a[i+1] < a[i]){
				moves.push(make_pair(i+1, i));
				a[i] += a[i+1];		
			}
		}
	}
	int m = moves.size();
	cout << m << "\n";
	for (int i = 0; i < m; ++i){
		cout << moves.front().first+1 << " " << moves.front().second +1 << "\n";
		moves.pop();
	}	
	return 0;
}
