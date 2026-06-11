#include <iterator>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
using namespace std;
int main(int argc, char **argv) {
  int N, M;
  cin >> N >> M;

  vector<int> liked;
  liked.resize(M + 1);
    cin >> ws;
  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; ++j) {
      int a;
      cin >> a;
      liked[a]++;
    }
  }

  cout << count_if(liked.begin(), liked.end(), [N](int v) { return v == N; }) << endl;

  return 0;
}