#include<bits/stdc++.h>
using namespace std;
const int MAXN = 262144;
int N;
int A[101010];
int B[101010];

int idx[2*MAXN];
void setv(int a, int v)
{
  idx[a += MAXN] += v;
  while((a = a/2))
    idx[a] = idx[2*a] + idx[2*a+1];
}
int getv(int a, int b)
{
  int ans = 0;
  a += MAXN; b += MAXN;
  while(a<=b)
  {
    if(a%2==1) ans += idx[a++];
    if(b%2==0) ans += idx[b--];
    a /= 2; b /= 2;
  }
  return ans;
}

long long cnt(int a)
{
  memset(idx, 0, sizeof idx);
  for(int i=0; i<N; ++i)
    if(A[i] >= a) B[i] = 1;
    else B[i] = -1;
  
  int in = N;
  long long ans = 0;
  for(int i=0; i<N; ++i)
  {
    setv(in, 1);
    in += B[i];
    ans += getv(0, in);
  }
  //printf("%d %lld\n", a, ans);
  return ans;
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%d", A+i);
  int lo = 0;
  int hi = (int)1e9+1;
  while(lo+1!=hi)
  {
    int mi = (lo+hi)/2;
    if(cnt(mi) >= (1LL*N*(N+1)/2+1)/2) lo = mi;
    else hi = mi;
  }
  printf("%d\n", lo);
  return 0;
}