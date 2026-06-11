#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int main()
{
    auto h = std::size_t(0);
    auto w = std::size_t(0);

    std::cin >> h >> w;

    auto white = int(0);
    auto s = std::vector<std::vector<char>>(h, std::vector<char>(w, 0));
    auto visited = std::vector<std::vector<bool>>(h, std::vector<bool>(w, false));
    for (std::size_t i = 0; i < h; ++i)
        for (std::size_t j = 0; j < w; ++j)
        {
            std::cin >> s[i][j];
            if (s[i][j] == '.') white++;
        }

    auto comp = [](auto a, auto b) { return std::get<2>(a) > std::get<2>(b); };

    // tuple -> (x,y,round), less round number is priotized in the queue (see the lambda expression above) 
    auto q =
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, decltype(comp)>(comp);

    auto sx = int(0);
    auto sy = int(0);
    auto gx = int(w - 1);
    auto gy = int(h - 1);

    auto dx = std::vector<int>({0, 1, 0, -1});
    auto dy = std::vector<int>({1, 0, -1, 0});

    q.emplace(sx, sy, 1);
    visited[static_cast<std::size_t>(sy)][static_cast<std::size_t>(sx)] = true;
    auto steps = std::vector<int>();
    while (!q.empty())
    {
        auto px = std::get<0>(q.top());
        auto py = std::get<1>(q.top());
        auto round = std::get<2>(q.top());

        q.pop();
        auto tx = int(0);
        auto ty = int(0);

        for (std::size_t i = 0; i < 4; ++i)
        {
            tx = px + dx[i];
            ty = py + dy[i];

            if (tx < 0 || static_cast<int>(w) <= tx || ty < 0 || static_cast<int>(h) <= ty) continue;

            if ((!visited[static_cast<std::size_t>(ty)][static_cast<std::size_t>(tx)]) &&
                s[static_cast<std::size_t>(ty)][static_cast<std::size_t>(tx)] == '.')
            {
                if (tx == gx && ty == gy)
                {
                    steps.emplace_back(round + 1);
                    continue;
                }

                visited[static_cast<std::size_t>(ty)][static_cast<std::size_t>(tx)] = true;
                q.emplace(tx, ty, round + 1);
            }
        }
    }

    if (steps.empty())
        std::cout << -1 << std::endl;
    else
        std::cout << white - *std::min_element(steps.begin(), steps.end()) << std::endl;

    return 0;
}
