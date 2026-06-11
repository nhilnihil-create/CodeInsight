#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
  int N, M;
  cin >> N;
  unordered_map <string, int> cards;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    cards[s]++;
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    string t;
    cin >> t;
    cards[t]--;
  }
  int ans = 0;
	for (unordered_map <string, int>::iterator it = cards.begin(); it != cards.end(); it++) {
		ans = max(ans, it->second);
	}
  cout << ans << endl;
  return 0;
}
