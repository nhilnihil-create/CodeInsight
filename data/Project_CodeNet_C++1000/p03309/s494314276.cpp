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
  int N;
  cin >> N;
  vector<int> A(N), B(N);

  for(int i = 0; i < N; i++) cin >> A[i];


  for(int i = 0; i < N; i++) {
    B[i] = A[i] - (i + 1);
  }

  sort(B.begin(), B.end());

  int b = B[N / 2];
  ll sum = 0;
  for(int i = 0; i < N; i++) {
    sum += abs(b - B[i]); 
  }

  cout << sum;

    return 0;
}
