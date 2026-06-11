#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	int N; std::cin >> N;
	std::string s; std::cin >> s;
    intt ans = 0;
    for (int i = 1; i < N - 1; i++) {
        intt count = 0;
        std::vector<int> R(26), L(26);
        for (int j = 0; j < i; j++)L[s[j] - 'a'] = 1;
        for (int k = i; k < N; k++)R[s[k] - 'a'] = 1;
        for (int l = 0; l < 26; ++l) {
            if (R[l] == 1 && L[l] == 1)count++;
        }
        ans = std::max(ans, count);
    }
    std::cout << ans << std::endl;
}