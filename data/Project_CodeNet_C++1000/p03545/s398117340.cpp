#include <bits/stdc++.h>
int main()
{
    int E;
    std::cin >> E;

    int a = (E / 1000) % 10;
    int b = (E / 100) % 10;
    int c = (E / 10) % 10;
    int d = (E / 1) % 10;

    std::vector<std::vector<int>> P = {{1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1}, {-1, 1, 1}, {-1, 1, -1}, {-1, -1, 1}, {-1, -1, -1}};
    std::array<char, 3> op = {};
    for (int i = 0; i < 8; ++i) {
        if (a + P[i][0] * b + P[i][1] * c + P[i][2] * d == 7) {
            for (int j = 0; j < 3; ++j) {
                if (P[i][j] == 1) {
                    op[j] = '+';
                } else {
                    op[j] = '-';
                }
            }
        }
    }
    std::cout << a << op[0] << b << op[1] << c << op[2] << d << "=7" << std::endl;
    return 0;
}