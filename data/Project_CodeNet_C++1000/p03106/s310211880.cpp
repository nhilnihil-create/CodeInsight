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
	int A, B, K;
	cin >> A >> B >> K;

	vector <int> div;
	for (int ii = max(A, B); ii > 0; --ii){
		if ( (A%ii==0) && (B%ii==0) ){
			div.push_back(ii);
		}
	}

	int cnt = 1;
	for (int ii = 0; ii < div.size(); ++ii){
		if (cnt==K){
			cout << div[ii] << "\n";
			break;
		}
		cnt++;
	}

	return 0;
}
