#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
int N; ll A[100001], B[100001];
int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) scanf("%ld", &A[i]);
  for(int i = 1; i <= N; ++i) scanf("%ld", &B[i]);
  ll sumlack = 0LL; vector<ll> surplus; int ans = 0;
  for(int i = 1; i <= N; ++i) {
    if(A[i] < B[i]) sumlack += B[i]-A[i], ++ans;
    else surplus.push_back(A[i]-B[i]);
  }
  sort(surplus.begin(), surplus.end(), greater<>());
  for(int i = 0; sumlack > 0 && i < surplus.size(); ++i) {
    sumlack -= surplus[i], ++ans;
  }
  if(sumlack > 0) ans = -1;
  printf("%d\n", ans);
}