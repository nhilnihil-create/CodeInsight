#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N; cin >> N;

	ll a[100];
	ll max_abs = 0;
	ll max_idx = -1;
	for (int i = 0;i < N;i++){
		cin >> a[i];
		if(abs(a[i]) > abs(max_abs)){
			max_abs = a[i];
			max_idx = i;
		}
	}

	vector<P> ans;

	if(max_abs < 0){
		for (int i = N-2;i >= 0;i--){
			while(a[i] > a[i+1]){
				a[i] += max_abs;
				ans.push_back(P(max_idx+1, i+1));
				if(abs(a[i]) > abs(max_abs)){
					max_abs = a[i];
					max_idx = i;
				}
			}
		}
	}else{
		for (int i = 1;i < N;i++){
			while(a[i] < a[i-1]){
				a[i] += max_abs;
				ans.push_back(P(max_idx+1, i+1));
				if(abs(a[i] > abs(max_abs))){
					max_abs = a[i];
					max_idx = i;
				}
			}
		}
	}

	cout << ans.size() << endl;

	for (int i = 0;i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;

}
