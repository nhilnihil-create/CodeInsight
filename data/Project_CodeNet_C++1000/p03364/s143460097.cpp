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
	int h; scanf("%d", &h);
	std::vector<std::string> s(h);
	for(int i = 0; i < h; i++) {
		cin >> s[i];

		s[i] += s[i];
	}
	for(int i = 0; i < h; i++) s.push_back(s[i]);
	
	int ans = 0;
	for(int q = 0; q < h; q++) {
		int p = 0;

		bool f = true;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < h; j++) {
				if(s[p + i][q + j] == s[p + j][q + i]) continue;
				f = false;
				break;
			}
		}
		
		ans += f * h;
	}
	printf("%d\n", ans);
	return 0;
}
