#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> t(n+2);
    std::vector<int> x(n+2);
    std::vector<int> y(n+2);
    for (int i = 1; i < n+1; i++)
    {
        std::cin >> t[i] >> x[i] >> y[i];
    }

    x[0] = 0;
    y[0] = 0;
    x[n + 1] = 0;
    y[n + 1] = 0;

    bool f = true;
    std::string ans;
    int dx;
    int dy;
    int dt;
    for (int i = 0; i < n; i++)
    {
        dx = std::abs(x[i + 1] - x[i]);
        dy = std::abs(y[i + 1] - y[i]);
        dt = t[i + 1] - t[i];

        if(!(dt >= dx + dy && dt%2 == (dx+dy)%2 )) {
            f = false;
        }
    }

    ans = f ? "Yes" : "No";

    std::cout << ans << "\n";
}