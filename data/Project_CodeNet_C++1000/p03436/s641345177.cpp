#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int main()
{
    using Grid = std::uint16_t;

    auto h = Grid(0);
    auto w = Grid(0);

    std::cin >> h >> w;

    auto white = Grid(0);
    auto s = std::vector<std::vector<char>>(h, std::vector<char>(w, 0));
    auto visited = std::vector<std::vector<bool>>(h, std::vector<bool>(w, false));
    for (Grid i = 0; i < h; ++i)
        for (Grid j = 0; j < w; ++j)
        {
            std::cin >> s[i][j];
            if (s[i][j] == '.') white++;
        }

    auto q = std::queue<std::tuple<Grid, Grid, Grid>>();

    auto sx = Grid(0);
    auto sy = Grid(0);
    auto gx = Grid(w - 1);
    auto gy = Grid(h - 1);

    auto dx = std::vector<int>({0, 1, 0, -1});
    auto dy = std::vector<int>({1, 0, -1, 0});

    auto goal_steps = std::vector<Grid>();
    visited[sy][sx] = true;
    q.emplace(sx, sy, 1);
    while (!q.empty())
    {
        auto px = std::get<0>(q.front());
        auto py = std::get<1>(q.front());
        auto steps = std::get<2>(q.front());
        q.pop();
        for (std::size_t i = 0; i < 4; ++i)
        {
            auto next_step = steps;
            auto tx = Grid(px + dx[i]);
            auto ty = Grid(py + dy[i]);

            if (tx < 0 || w <= tx || ty < 0 || h <= ty) continue;

            if (visited[ty][tx]) continue;

            if (!visited[ty][tx] && s[ty][tx] == '.')
            {
                if (tx == gx && ty == gy)
                {
                    goal_steps.emplace_back(++next_step);
                    continue;
                }

                visited[ty][tx] = true;
                q.emplace(tx, ty, ++next_step);
            }
        }
    }

    if (goal_steps.empty())
        std::cout << -1 << std::endl;
    else
        std::cout << white - *std::min_element(goal_steps.begin(), goal_steps.end()) << std::endl;
    return 0;
}