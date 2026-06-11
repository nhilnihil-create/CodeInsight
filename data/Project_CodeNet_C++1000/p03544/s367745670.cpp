#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int64_t> L(86);

    L[0] = 2;
    L[1] = 1;

    if (N >= 2)
    {
        for (auto i = 2; i <= N; i++)
        {
            L[i] = L[i - 1] + L[i - 2];
        }
    }

    std::cout << L[N] << std::endl;
}
