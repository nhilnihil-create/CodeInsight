#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;
    long long h, w, a, b, cnt = 0;
    std::cin >> n >> h >> w;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        if (h <= a && w <= b) { cnt++; }
    }
    std::cout << cnt << std::endl;
    return 0;
}