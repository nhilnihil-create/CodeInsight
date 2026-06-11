#include <bits/stdc++.h>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
int N;
vector<ll> A,B;

int main(void)
{
  cin >> N;
  for (int i = 0; i < N; ++i)
    {
      ll a;
      cin >> a;
      A.push_back(a);
    }
  for (int i = 0; i < N; ++i)
    {
      ll b;
      cin >> b;
      B.push_back(b);
    }
  ll res=0;
  for(int digit=29;digit>=0;digit--)
    {
      ll high=1LL<<(digit+1);
      ll low=1LL<<(digit);
      for (int i = 0; i < N; ++i)
	{
	  A[i]%=high;
	  B[i]%=high;
	}
      sort(B.begin(),B.end());
      ll num=0;
      for (int i = 0; i < N; ++i)
	{
	  ll add=0;
	  if(low-A[i]>=0)
	    {
	      add+=lower_bound(B.begin(),B.end(),high-A[i])-lower_bound(B.begin(),B.end(),low-A[i]);
	    }
	  else
	    {
	      add+=lower_bound(B.begin(),B.end(),high-A[i])-B.begin();
	      add+=lower_bound(B.begin(),B.end(),high)-lower_bound(B.begin(),B.end(),high+low-A[i]);
	    }
	  num+=add;
	}
      if(num&1) res+=low;
    }
  cout << res << endl;
  return 0;
}
