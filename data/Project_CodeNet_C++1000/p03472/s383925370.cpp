#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> a;
vector<long long> b;

bool comp(long long i, long long j) {
  if (a[i] == a[j])
    return b[i] < b[j];
  else
    return a[i] > a[j];
}

int main(int argc, char* argv[]) {
  long long N, H;
  cin >> N >> H;

  a.resize(N);
  b.resize(N);
  vector<long long> indices(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
    indices[i] = i;
  }

  sort(indices.begin(), indices.end(), comp);

  int best_index = indices[0];
  vector<long long> big_b;
  for (int i = 0; i < N; ++i) {
    if (i == best_index)
      continue;
    if (b[i] > a[best_index]) {
      big_b.push_back(b[i]);
    }
  }

  sort(big_b.begin(), big_b.end(), greater<long long>());

  int i;
  for (i = 0; i < big_b.size(); ++i) {
    H -= big_b[i];
    if (H <= 0) {
      cout << i + 1 << endl;
      return 0;
    } else if (H - a[best_index] <= 0) {
      cout << i + 2 << endl;
      return 0;
    } else if (H - b[best_index] <= 0) {
      cout << i + 2 << endl;
      return 0;
    }
  }

  if (a[best_index] > b[best_index]) {
    cout << ceil((long double) H / a[best_index]) + i << endl;
  } else {
    cout << (long long)ceil((long double) (H - b[best_index]) / a[best_index]) + i + 1 << endl;
  }

  return 0;
}