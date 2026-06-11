#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  int N;
  cin >> N;
  vector<string> W(N);
  bool ans = true;
  rep(i,N)
  {
    cin >> W[i];
  }
  rep(i,N-1)
  {
    int M = W[i].size();
    if(W[i].back()!=W[i+1].front())
    {
      ans = false;
    }
    for(int j=i+1;j<N;j++)
    {
      if(W[i]==W[j])
      {
        ans = false;
      }
    }
  }
  if(ans == true)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
  return 0;
}
