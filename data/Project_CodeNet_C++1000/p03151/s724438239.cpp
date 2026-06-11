#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N;
	cin >> N;
    vector<int>A(N);
    vector<int>B(N);
    int ans = 0;
    int res = 0;
    vector<int>cnt;
	for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		if (A[i] >= B[i]) {
            cnt.push_back(A[i]-B[i]);
        }
		else { 
            res+=(B[i]-A[i]); 
            ans++; 
        }
	}
	sort(cnt.begin(), cnt.end()); 
    reverse(cnt.begin(), cnt.end());
	for (int i = 0; i < cnt.size(); i++) {
		if (res > 0) { 
            res -= cnt[i];
            ans++;
        }
	}
	if (res > 0) {
        ans = -1;
    }
	cout << ans << endl;
}
