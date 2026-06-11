#include <iostream>

using namespace std; 

int main() {
  // BE EXTRA CAREFUL WHEN TRANSLATING SCIENTIFIC NOTATION INTO NUMBERS
  // IDEALLY, PASTE IT AS A CONSTANT
  // 1E5 IS NOT TEN THOUSAND IT IS A HUnDRED THOUSAND
  // THIS IS NOT THE FIRST TIME MAKING THIS MISTAKE
  int Q; cin >> Q;
  int l[100000];
  int r[100000];
  for (int i = 0; i < Q; i++) {
    cin >> l[i] >> r[i];
  }

  int res[100001] = {0}; // 0 indicates non-2017-like, 1 indicates 2017-like prime

  // O(R sqrt(R))
  for (int i = 3; i < 100000; i += 2) {
    bool is_prime = true;

    int j = 2;
    while(j * j <= i) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
      j++;
    }

    if (!is_prime) continue;

    bool is_2017_like = true;

    int k = 2;
    while(k * k <= (i + 1) / 2) {
      if ((i + 1) / 2 % k == 0) {
        is_2017_like = false;
        break;
      }
      k++;
    }

    if (!is_2017_like) continue;

    res[i] = 1;
  }

  // cumsum
  for (int i = 0; i < 100000; i++) {
    res[i + 1] += res[i];
  }

  for (int i = 0; i < Q; i++) {
    cout << res[r[i]] - res[l[i] - 1] << endl;
  }
}