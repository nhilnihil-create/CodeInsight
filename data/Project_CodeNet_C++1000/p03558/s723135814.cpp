#define _CRT_SECURE_NO_WARNINGS
#include <array>
#include <cstdio>
#include <deque>
#include <utility>

using namespace std;

// 0-1 BFS
int main()
{
    int K;
    if (scanf("%d", &K) < 1) return 0;

    array<int, 100000> dist;
    dist.fill(100000);

    deque<int> deq;

    dist[1] = 1;

    deq.push_back(1);

    while (deq.size())
    {
        int u = deq.front();
        deq.pop_front();

        // コスト 0 の辺の遷移は deque の先頭に
        if (dist[u] < dist[u * 10 % K])
        {
            dist[u * 10 % K] = dist[u];
            deq.push_front(u * 10 % K);
        }
        // コスト 1 の辺の遷移は deque の末尾に
        if (dist[u] + 1 < dist[(u + 1) % K])
        {
            dist[(u + 1) % K] = dist[u] + 1;
            deq.push_back((u + 1) % K);
        }
    }

    printf("%d\n", dist[0]);
    return 0;
}
