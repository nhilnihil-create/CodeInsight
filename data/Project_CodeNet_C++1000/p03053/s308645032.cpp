#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

int bfs(std::vector<std::vector<int>> A)
{
    int H = A.size();
    int W = A[0].size();

    std::queue<ll> Q;
    // looking for start
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (A[i][j] == 0)
            {
                Q.push(i * W + j);
                // std::cout << i << " " << j << std::endl;
            }
        }
    }

    int l = 0;
    int maxcount = 0;
    while (true)
    {
        l++;
        ll v = Q.front();
        Q.pop();

        int i = v / W;
        int j = v % W;

        if (i != 0 && A[i - 1][j] == -1)
        {
            Q.push((i - 1) * W + j);
            A[i - 1][j] = A[i][j] + 1;
            maxcount = std::max(A[i - 1][j], maxcount);
        }

        if (i != H - 1 && A[i + 1][j] == -1)
        {
            Q.push((i + 1) * W + j);
            A[i + 1][j] = A[i][j] + 1;
            maxcount = std::max(A[i + 1][j], maxcount);

        }

        if (j != 0 && A[i][j - 1] == -1)
        {
            Q.push(i * W + (j - 1));
            A[i][j - 1] = A[i][j] + 1;
            maxcount = std::max(A[i][j - 1], maxcount);

        }

        if (j != W - 1 && A[i][j + 1] == -1)
        {
            Q.push(i * W + (j + 1));
            A[i][j + 1] = A[i][j] + 1;
            maxcount = std::max(A[i][j + 1], maxcount);

        }

        if (Q.empty())
            break;
        
    }

    return maxcount;
}

int main()
{
    int H, W;
    std::cin >> H;
    std::cin >> W;

    std::vector<std::vector<int>> A(H);
    for (int i = 0; i < H; i++)
    {
        A[i] = std::vector<int>(W);
        for (int j = 0; j < W; j++)
        {
            char c;
            std::cin >> c;
            if (c == '#')
                A[i][j] = 0;
            else
                A[i][j] = -1;
        }
    }

    std::cout << bfs(A) << std::endl;

    return 0;
}