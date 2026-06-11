#include <bits/stdc++.h>
using namespace std;

void draw_card(map<string, int> &cards, int num, int increment) {
  for (int i = 0; i < num; i++) {
    string card;
    cin >> card;
    cards[card] = cards[card] + increment;
  }
}

int main() {
  map<string, int> cards;

  int N, M;
  cin >> N;
  draw_card(cards, N, 1);

  cin >> M;
  draw_card(cards, M, -1);

  int max_num = 0;
  for (auto itr = cards.begin(); itr != cards.end(); itr++) {
    max_num = max(max_num, itr->second);
  }

  cout << max_num << endl;
}

