#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

bool isPrime(int a) {
  for (int i = 2; i*i <= a; ++i)
  {
    if (a%i==0) return false;
  }
  return true;
}

int main()
{
  int n;
  cin>>n;
  int cnt=0;
  for (int i = 5; i <= 55555; ++i)
  {
    if (!isPrime(i)) continue;
    if (i%5==1) {
      cout<<i<<" ";
      cnt++;
    }
    if (cnt==n) return 0;
  }
}