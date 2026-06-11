#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	int n; cin >> n;

	auto getType = [](std::string s) {
		if(s == "Vacant") return 0;
		if(s == "Female") return 1;
		if(s == "Male") return 2;
	};
	
	int left = 0, right = n - 1;
	std::string L, R;
	
	cout << left << endl;
	cin  >> L;
	if(L == "Vacant") return 0;

	cout << right << endl;
	cin >> R;
	if(R == "Vacant") return 0;
	
	while(true) {
		int mid = (left + right) >> 1;
		cout << mid << endl;
		std::string M; cin >> M;
		if(M == "Vacant") return 0;

		if((right - mid + 1) % 2 != (M == R)) {
			left = mid;
			L = M;
		} else {
			right = mid;
			R = M;
		}
	}
	return 0;
}
