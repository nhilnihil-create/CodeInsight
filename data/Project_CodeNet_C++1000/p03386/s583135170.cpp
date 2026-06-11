#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll A, B;
	int K;
	cin >> A >> B >> K;
	set<ll> st;
	for (ll i = A; i <min(A+K,B+1); i++) {
		st.insert(i);
	}
	for (ll i = B; i>max(B-K,A-1); i--){
		st.insert(i);
	}
	for (ll s : st) {
		cout << s << endl;	
	}
	return 0;
}
