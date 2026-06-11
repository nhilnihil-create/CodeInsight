#include <string>
#include <vector>
#include <iostream>
#define int long long
using namespace std;

const int N = 17, P = 1 << N;

bool b[P];
int n, a[N][N], maxi[P], p[N], c[P];

int group(int i) {
  if(c[i] == 1)
    return 0;
  if(b[i])
    return maxi[i];
  b[i] = true;
  vector<int> l;
  for(int j = i, k = 0; k < n; j /= 2, k++)
    if(j % 2 == 1)
      l.push_back(k);
  for(int j = 0; j < c[i]; j++)
    for(int k = j+1; k < c[i]; k++)
      maxi[i] += a[l[j]][l[k]];
  for(int val = 0; val < p[c[i]-1]; val++) {
    int sum = p[l[c[i]-1]];
    for(int j = 0, k = val; j < c[i]-1; j++, k /= 2)
      if(k % 2 == 1)
        sum += p[l[j]];
    if(sum != i && sum != 0) {
      maxi[i] = max(maxi[i], group(sum) + group(i - sum));
    }
  }
  return maxi[i];
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  for(int i = 0; i < N; i++)
    p[i] = 1 << i;
  for(int i = 0; i < P; i++) {
    int j = i;
    while(j != 0) {
      c[i] += j % 2;
      j /= 2;
    }
  }
  
  cin >> n;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> a[i][j];
  
  cout << group((1 << n) - 1);
}