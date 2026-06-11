#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int Q;
int sum[100000] = {0};
vector<int> q;

int main() {
  for(int i = 3; i <= 99999; i = i + 2) {
    int x = i;
    for(int j = 2; j * j <= i; j++) {
      while(x%j==0) {
        x /= j;
      }
    }
    if(i == x) {
      q.push_back(i);
    }
  }

  // rep(i, 30) {
  //   cout << q[i] << endl;
  // }

  for(int i = 0; i < q.size(); i++) {
    int p = (q[i] + 1) / 2;
    int x = p;
    for(int j = 2; j * j <= x; j++) {
      while(p%j==0) {
        p /= j;
      }
    }
    if(p == x) {
      if(i == 0) {
        sum[q[0]] = 1;
        continue;
      }
      for(int j = q[i-1]+1; j < q[i]; j++) {
        sum[j] = sum[q[i-1]];
      }
      sum[q[i]] = sum[q[i-1]] + 1;
      if(i == q.size() - 1) {
        for(int k = q[q.size()-1]; k <= 99999; k++) {
          sum[k] = sum[q[q.size()-1]];
        }
      }
    } else {
      if(i == 0) {
        sum[q[0]] = 0;
        continue;
      }
      for(int j = q[i-1]+1; j <= q[i]; j++) {
        sum[j] = sum[q[i-1]];
      }
      if(i == q.size() - 1) {
        for(int k = q[q.size()-1]; k <= 99999; k++) {
          sum[k] = sum[q[q.size()-1]];
        }
      }
    }
  }
 /* 
 for(int i = sum[q[q.size()-1]]; i <= 99999; i++) {
    sum[i] = sum[q[q.size()-1]];
  }
*/

  // cout << q[0] << endl;
  cin >> Q;
  rep(i, Q) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l-1] << endl;
  }
  return 0;
}