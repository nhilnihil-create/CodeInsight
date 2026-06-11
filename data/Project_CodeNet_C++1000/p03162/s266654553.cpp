// g++ -std=c++17 -o2 -Wall .\testing.cpp -o test

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin>>N;
  int a[N], b[N], c[N];
  for(int i=0; i<N; i++)
    cin>>a[i]>>b[i]>>c[i];

  int Dp[]={a[0],b[0], c[0]};
  int M[]={0,0,0};
  for(int i=1; i<N; i++)
  {
    M[0] = max(a[i]+Dp[1], a[i]+Dp[2]);
    M[1] = max(b[i]+Dp[0], b[i]+Dp[2]);
    M[2] = max(c[i]+Dp[0], c[i]+Dp[1]);
    for(int i=0; i<3; i++)
      Dp[i]=M[i];
  }
  cout<<*max_element(Dp, Dp+3);

}
