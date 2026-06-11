#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);

  for(int i = 0; i < N; i++) cin >> A[i];

  int ans = 1;
  int sum = K;
  while(sum <  N) {
    sum += (K - 1);
    ans++;
  }

  cout << ans;
    return 0;
}
