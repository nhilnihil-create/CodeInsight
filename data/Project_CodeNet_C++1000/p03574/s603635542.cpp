/*
  Contest 075
  B - Minesweeper
  Rakesh Kumar --> 11/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int h = 0 , w = 0;
    std::cin >> h >> w;
    std::cin.ignore();
    std::vector<std::string> grid;
    while (h--) {
        std::string s;
        std::getline(std::cin, s);
        grid.emplace_back(s);
    }

    for (int r = 0; r < static_cast<int>(grid.size()); ++r) {
        for (int c = 0; c < static_cast<int>(grid[r].size()); ++c) {
            if (grid[r][c] == '.') {
                int count = 0;
                if (r - 1 >= 0 && grid[r - 1][c] == '#')
                    ++count;
                if (r + 1 < static_cast<int>(grid.size()) && grid[r + 1][c] == '#')
                    ++count;
                if (c - 1 >= 0 && grid[r][c - 1] == '#')
                    ++count;
                if (c + 1 < static_cast<int>(grid[r].size()) && grid[r][c + 1] == '#')
                    ++count;
                if (r - 1 >= 0 && c - 1 >= 0 && grid[r - 1][c - 1] == '#')
                    ++count;
                if (r - 1 >= 0 && c + 1 < static_cast<int>(grid[r].size()) && grid[r - 1][c + 1] == '#')
                    ++count;
                if (r + 1 < static_cast<int>(grid.size()) && c - 1 >= 0 && grid[r + 1][c - 1] == '#')
                    ++count;
                if (r + 1 < static_cast<int>(grid.size()) && c + 1 < static_cast<int>(grid[r].size()) && grid[r + 1][c + 1] == '#')
                    ++count;
                std::cout << count;
            } else {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
