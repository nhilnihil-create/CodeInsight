#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;


int main()
{
  ll N,ans=0,temp=0,same=0;
  cin >> N;
  vector<ll> A(N), sum(N);
  rep(i,N)
  {
    cin >> A[i];
  }

  sum[0] = A[0];
  for (int i = 1; i < N; i++)
  {
    sum[i] = sum[i - 1] + A[i];
  }

  sort(all(sum));

  rep(i,N)
  {
    if (sum[i]==0)
    {
      ans++;
    }
    if(sum[i]>0)
      {
        break;
      }
  }



  for (int i = 0; i < N-1; i++)
  {
      if (sum[i] == sum[i+1])
        {
          temp++;
        }
      if(sum[i]!=sum[i+1]||(i==(N-2)))
        {
          ans += (temp + 1) * temp / 2;
          temp = 0;
        }
  }

  cout << ans << endl;
  return 0;
}
