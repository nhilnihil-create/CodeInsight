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
  ll Q, l, r,sum_sim=0,ans,fans;
  vi prime(0),prime_check(100000,0),similar(100000,0),ANS(100000);

  cin >> Q;

  rep(i,100000)
  {
    if(i==0||i==1)
      continue;
    else if (i==2)
    {
      prime.push_back(3);
      prime_check[2] = 1;
    }
    else
    {
      rep(j,prime.size())
      {
        if((i+1)%prime[j]==0||(i+1)%2==0)
          goto OUT;
      }
      prime.push_back(i + 1);
      prime_check[i] = 1;
    OUT:;
    }
  }

  rep(i,prime.size())
  {
    if((prime[i]*2-1)<=100000)
    {
      similar[prime[i]*2-2] = 1;
    }
    if((prime[i]*2)-1>=100000)
      break;
  }
  similar[2] = 1;

  ans = 0;

  rep(i, 100000)
  {
    if (prime_check[i] == 1 && similar[i] == 1)
      {
        ans++;
      }
      ANS[i] = ans;
  }

  rep(i,Q)
  {
    cin >> l >> r;
    if(prime_check[l-1]==1&&similar[l-1]==1)
      {
        fans = ANS[r - 1] - ANS[l - 1]+1;
      }
    else fans = ANS[r - 1] - ANS[l - 1];

    cout << fans<< endl;
  }
  return 0;
}
