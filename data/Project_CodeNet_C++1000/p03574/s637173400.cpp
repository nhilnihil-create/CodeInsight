#include <bits/stdc++.h>
bool judge(const char& a)
{
    bool ans;
    if (a == '.') {
        ans = true;
    } else {
        ans = false;
    }
    return ans;
}


int main()
{
    int h, w;
    std::cin >> h >> w;
    std::array<std::string, 55> S;
    std::array<std::array<int, 55>, 55> N = {};
    for (int i = 0; i < h; ++i) {
        std::cin >> S.at(i);
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!judge(S[i][j])) {
                if (i > 0) {
                    N[i - 1][j] += 1;
                }
                if (i < h) {
                    N[i + 1][j] += 1;
                }
                if (j > 0) {
                    N[i][j - 1] += 1;
                }
                if (j < w) {
                    N[i][j + 1] += 1;
                }
                if (i > 0 && j > 0) {
                    N[i - 1][j - 1] += 1;
                }
                if (i > 0 && j < w) {
                    N[i - 1][j + 1] += 1;
                }
                if (i < h && j > 0) {
                    N[i + 1][j - 1] += 1;
                }
                if (i < h && j < w) {
                    N[i + 1][j + 1] += 1;
                }
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (judge(S[i][j])) {
                S[i].replace(j, 1, std::to_string(N[i][j]));  //= static_cast<char>(N[i][j]);
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        std::cout << S.at(i) << std::endl;
    }
    return 0;
}