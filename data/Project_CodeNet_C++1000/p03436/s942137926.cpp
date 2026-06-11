#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int H, W;
    std::cin >> H >> W;
    std::vector<std::string> s(H);
    int black_count = 0;
    for (int i = 0; i < H; i++) {
        std::cin >> s[i];
        for (int j = 0; j < W; j++)
            if (s[i][j] == '#')
                black_count++;
    }

    const auto pos = [&](int x, int y) {
        return y * W + x;
    };

    std::queue<int> que;
    que.emplace(pos(0, 0));

    const int INF = H * W;
    std::vector<int> d(H * W, INF);
    d[pos(0, 0)] = 0;

    while (!que.empty()) {
        int curr = que.front(); que.pop();
        int x = curr % W;
        int y = curr / W;

        const int dx[] = {-1, 0, 1, 0};
        const int dy[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int next = pos(nx, ny);

            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (s[ny][nx] == '#') continue;

            if (d[curr] + 1 < d[next]) {
                d[next] = d[curr] + 1;
                que.emplace(next);
            }
        }
    }

    if (d[pos(W - 1, H - 1)] == INF)
        std::cout << -1 << std::endl;
    else
        std::cout << H * W - (d[pos(W - 1, H - 1)] + black_count + 1) << std::endl;
        
    return 0;
}