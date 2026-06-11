#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  deque<int> q;
  for (int i = 0; i < N; ++i) {
    int b;
    cin >> b;
    q.push_back(b);
  }

  vector<int> ret;
  while (!q.empty()) {
    int last_index = -1;
    int just_index = -1;
    for (int i = 1; i <= q.size(); ++i) {
      if (q[i - 1] < i && last_index != -1)
        last_index = i;
      if (q[i - 1] == i)
        just_index = i;
    }
    if (just_index != -1)
      last_index = just_index;
    else if (last_index == -1) {
      cout << -1 << endl;
      return 0;
    }
    ret.push_back(q[last_index - 1]);
    q.erase(q.begin() + last_index - 1);
  }

  for (int i = N - 1; i >= 0; --i) {
    cout << ret[i] << endl;
  }

  return 0;
}