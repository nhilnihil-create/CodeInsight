#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower, islower
#include <math.h> //pow

#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
//using ll = long long; using ld = long double;
//using P = pair<int, int>;

int N = 55555;

void Eratosthenes2(int* arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = 1;
    }
    arr[0] = 0; arr[1] = 0;
    for (int i = 2; i * i <= N; i++) {
        if (!arr[i]) continue; 
        for (int j = i * i; j <= N; j += i) {
            arr[j] = 0;
        }
    }
    for (int i = 2; i < N; i++) {
        if (arr[i]) {
            //std::cout << i << std::endl;
        }
    }
}

int main() {
  int arr[N];
  Eratosthenes2(arr);
  int n;
  cin >> n;
  int ans[n];
  int j = 0;
  int sum = 0;
  rep(i,N) {
    if (arr[i] && i % 5 == 1) {
        ans[j] = i;
        j++;
        if (j > n-1) break;
    }
  }


  rep(i,n) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}

