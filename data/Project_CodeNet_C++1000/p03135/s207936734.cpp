
#include <bits/stdc++.h>

using namespace std;

void Main()
{
    int t, x;
    cin >> t >> x;

    cout << (long double)t / (long double)x;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cout << std::fixed << std::setprecision(10);

#ifdef DEBUG_BUILD
    while (true)
    {
        Main();
        cout << std::endl;
    }
#endif

    Main();
    cout << endl;

    return 0;
}