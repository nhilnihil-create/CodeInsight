#include <bits/stdc++.h>
using namespace std;

int shortest(int D, int G, vector<int> p, vector<int> &c) {
  if (G <= 0)
    return 0;
  int stay1, stay2, shortest_number = -1;
  for (int i = 0; i < D; i++) {
    if (p.at(i) == 0)
      continue;
    if (G >= (i + 1) * 100 * p.at(i) + c.at(i)) {
      stay1 = p.at(i);
      p.at(i) = 0;
      stay2 = shortest(D, G - (i + 1) * 100 * stay1 - c.at(i), p, c) + stay1;
      p.at(i) = stay1;
    }
    else if(G >= (i + 1) * 100 * p.at(i)) {
      stay2 = p.at(i);
    }
    else {
      int g = G;
      for (int j = 0; j < p.at(i); j++) {
        g -= (i + 1) * 100;
        if (g <= 0) {
          stay2 = j + 1;
          break;
        }
      }
    }
    if (shortest_number > stay2 || shortest_number == -1) {
      shortest_number = stay2;
    }
  }
  return shortest_number;
}

int main() {
  int D;
  int G;
  cin >> D >> G;
  vector<int> p(D), c(D);
  for (int i = 0; i < D; i++)
    cin >> p.at(i) >> c.at(i);
  cout << shortest(D, G, p, c) << endl;
}