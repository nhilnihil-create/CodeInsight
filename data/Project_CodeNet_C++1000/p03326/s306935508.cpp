#include <iostream>
#include <vector>
#include <algorithm>

using int64 = long long;

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int64> x(N), y(N), z(N);
    for (int i = 0; i < N; i++)
        std::cin >> x[i] >> y[i] >> z[i];

    int64 max = 0;
    for (int i = 0; i < 8; i++) {
        int sign_x = (i >> 2 & 1) ? 1 : -1;
        int sign_y = (i >> 1 & 1) ? 1 : -1;
        int sign_z = (i >> 0 & 1) ? 1 : -1;

        std::vector<int64> v;
        for (int j = 0; j < N; j++)
            v.emplace_back(x[j] * sign_x + y[j] * sign_y + z[j] * sign_z);

        std::sort(v.rbegin(), v.rend());
        int64 sum = 0;
        for (int j = 0; j < M; j++)
            sum += v[j];

        max = std::max(max, sum);
    }

    std::cout << max << std::endl;
    return 0;
}
