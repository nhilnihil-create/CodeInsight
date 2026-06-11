#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    size_t h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (size_t i = 0; i < h; ++i) cin >> grid[i];
    bool enable = true;
    for (size_t y = 0; y < h; ++y) {
        for (size_t x = 0; x < w; ++x) {
            if (grid[y][x] == '#') {
                if (!((y != 0 && grid[y - 1][x] == '#') || (x != (w - 1) && grid[y][x + 1] == '#') || (y != (h - 1) && grid[y + 1][x] == '#') || (x != 0 && grid[y][x - 1] == '#'))) {
                    enable = false;
                    break;
                }
            }
        }
        if (!enable) break;
    }
    cout << (enable ? "Yes" : "No") << endl;
    return EXIT_SUCCESS;
}