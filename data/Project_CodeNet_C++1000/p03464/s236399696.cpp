#include <iostream>

using namespace std;

typedef long long ll;

void failure () {
  cout << -1 << endl;
  exit(0);
}

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];
ll lb [MAX_N], ub [MAX_N];

int main () {
  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }

  if (arr[k - 1] != 2) failure();
  
  lb[k] = 2;
  ub[k] = 2;

  for (int i = k - 1; i >= 0; i--) {
    lb[i] = lb[i + 1];
    ub[i] = ub[i + 1] + arr[i] - 1;

    if (i != 0) {
      ll to_add = (-lb[i]) % arr[i - 1];
      if (to_add < 0) to_add += arr[i - 1];
      lb[i] += to_add;

      ll to_rem = ub[i] % arr[i - 1];
      ub[i] -= to_rem;

      if (lb[i] > ub[i]) failure();
    }
  }

  cout << lb[0] << " " << ub[0] << endl;
}
