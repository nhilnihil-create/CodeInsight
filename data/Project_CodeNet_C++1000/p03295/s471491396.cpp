#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
#include <climits>
#include <bitset>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;

int main()
{
    struct Edge
    {
        Edge(int from, int to) : _from(from), _to(to){}
        int _from, _to;
    };

    std::ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::vector<Edge> edges;
    std::vector<bool> bridges(N-1);

    for (auto i=0; i<M; ++i)
    {
        int from, to;
        std::cin >> from >> to;
        from--;
        to--;
        edges.emplace_back(Edge(from, to));
    }

    std::sort(edges.begin(), edges.end(),
            [](const Edge& lhs, const Edge& rhs) { return lhs._to < rhs._to; });

    auto result = 0;
    for (auto& e : edges)
    {
        bool shouldBrake = true;
        for (auto j=e._from; j<e._to; ++j)
        {
            // from ~ to までのどこかが壊れてた
            if (bridges[j])
            {
                shouldBrake = false;
                break;
            }
        }

        if (shouldBrake)
        {
            bridges[e._to-1] = true;
            result++;
        }
    }

    std::cout << result << std::endl;
}
