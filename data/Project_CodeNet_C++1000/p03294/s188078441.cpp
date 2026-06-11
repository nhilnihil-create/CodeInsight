#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
   int N;
   cin >> N;
   vector<int> a(N,0);
   rep(i,N) cin >> a.at(i);
   int sum = 0;
   rep(i,N) sum += a[i];
   cout << sum - N << endl;
}