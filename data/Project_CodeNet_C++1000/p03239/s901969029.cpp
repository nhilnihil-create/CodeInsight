#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, const char *argv[]) {
  int N, T, c, t;
  cin >> N >> T;
  vector<int> cost;

  for (int i = 0; i < N; i++) {
    cin >> c >> t;
    if(t <= T){
      cost.push_back(c);
    }
  }
  if(cost.size() == 0){
    cout << "TLE" << endl;
    return 0;
  }
  sort(cost.begin(), cost.end());
  cout << cost[0] << endl;

  return 0;
}
