#pragma GCC optimize("Ofast")
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>

using namespace std;

#define ll long long
#define ull unsigned long long
const ll MOD = 1000000007;
#define rep(i,n) for (int i = 0; i < (n); ++i)

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
	string S;
	cin >> S;
	int N = S.size();

	int cnt = 0;
	stack<int> st;
	for (int ii = 0; ii < N; ++ii){
		int val = S[ii] - '0';
		if (st.size()==0){
			st.push(val);
		} else {
			int top = st.top();
			if (top ^ val == 1){
				cnt += 2;
				st.pop();
			} else {
				st.push(val);
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}
