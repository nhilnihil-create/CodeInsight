#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

struct Spell
{
  char name;
  int direction;
};

int final_index(
    const std::string& board,
    const std::vector<Spell>& spells,
    int index)
{
  const int n = static_cast<int>(board.size());
  for (const auto& s : spells) {
    if (board[index] == s.name) {
      index += s.direction;
      if (index < 0 || index >= n) break;
    }
  }
  return index;
}

int solve(const std::string& board, const std::vector<Spell>& spells)
{
  std::vector<int> indexes(board.size());
  std::iota(indexes.begin(), indexes.end(), 0);

  return std::distance(
      std::partition_point( indexes.begin(),
        indexes.end(),
        [&board, &spells](int i) {
          return final_index(board, spells, i) < 0;
        }),
      std::partition_point(
        indexes.begin(),
        indexes.end(),
        [&board, &spells](int i) {
          return final_index(board, spells, i) < static_cast<int>(board.size());
        }));
}

int main()
{
  int n, q;
  std::string s;
  std::cin >> n >> q >> s;

  std::vector<Spell> spells(q);
  char d;
  for (int i = 0; i < q; ++i) {
    std::cin >> spells[i].name >> d;
    spells[i].direction = d == 'L' ? -1 : 1;
  }

  std::cout << solve(s, spells) << std::endl;
}
