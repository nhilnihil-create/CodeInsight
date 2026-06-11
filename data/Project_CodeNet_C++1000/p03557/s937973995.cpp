#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << "   ";
		}
		cout << endl;
	}
}




int main(){//
	int N;
	cin >> N;
	vector<ll> A(N), B(N), C(N);
	for(int i=0; i<N; i++) cin >> A[i];
	for(int i=0; i<N; i++) cin >> B[i];
	for(int i=0; i<N; i++) cin >> C[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	ll ans = 0;
	for(int b=0; b<N; b++){
		auto iter = lower_bound(A.begin(), A.end(), B[b]);
		auto num_a = iter - A.begin();

		auto iter2 = upper_bound(C.begin(), C.end(), B[b]);
		auto index = iter2 - C.begin();
		auto num_c = C.size() - index;
		//cout << " index: " << index << " num_c: " << num_c << endl;
		ans += num_a * num_c;
	}

	cout << ans << endl;

}
