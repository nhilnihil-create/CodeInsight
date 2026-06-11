#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool primes[100001];
bool primes_like_2017[100001];
int range_sum[100001];

int Q;
int l[100001], r[100001];

int main(int argc, char* argv[]) {
  cin >> Q;
  for (int i = 0; i < Q; i++)
    cin >> l[i] >> r[i];

  primes[0] = primes[1] = false;
  primes_like_2017[0] = false;
  primes_like_2017[1] = false;
  primes_like_2017[2] = false;
  for (int i = 2; i <= 100000; i++)
    primes[i] = true;

  for (int i = 2; i * i <= 100000; i++) {
    if (!primes[i])
      continue;

    for (int j = 2; i * j <= 100000; j++)
      primes[i * j] = false;
  }

  for (int i = 3; i <= 100000; i++)
    primes_like_2017[i] = i % 2 == 1 && primes[i] && primes[(i + 1) / 2];

  range_sum[0] = 0;
  for (int i = 1; i <= 100000; i++)
    range_sum[i] = range_sum[i - 1] + (primes_like_2017[i] ? 1 : 0);

  for (int i = 0; i < Q; i++)
    cout << range_sum[r[i]] - range_sum[l[i] - 1] << endl;

  return 0;
}
