#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    int ar[n], ans = 0;
    int tmp = n + 1;
    for (int i = 0; i < n; i++) { std::cin >> ar[i]; }
    for (int i = 0; i < n - 1; i++)
    {
        if (ar[i] == ar[i + 1])
        {
            ans++;
            ar[i + 1] = tmp++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}