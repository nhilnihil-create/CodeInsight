#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int maxv = min(a, b);
  if(b > a) swap(a, b);
  int minv = max(a + b - n, 0);
  cout << maxv << " "<< minv << endl;
}