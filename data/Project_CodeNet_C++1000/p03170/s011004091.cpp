#include <bits/stdc++.h>
using namespace std;

#define pb(a) push_back(a)
#define vi vector<int>
#define loop(i, n) for(int i=1;i<=n;i++)
#define loop0(i, n) for(int i=0;i<n;i++)
#define in(i) scanf("%d", &i);
#define out(i) printf("%d", i)

int n, k, a[101];
bool dp[100001];
// dp[i] current player can win from here.
// return true if there is a dp[i-a[x]] such
// that it is false that is the current player
// after this turn ie the next player loses.

int main()
{
  in(n);
  in(k);
  loop(i, n)
  {
    in(a[i]);
    dp[a[i]]=1;
  }

  loop(i, k)
  {
    loop(j, n)
    {
      if(i>=a[j] && dp[i-a[j]]==0)
      {
        dp[i]=true;
        break;
      }
    }
  }

  if(dp[k])
    cout<<"First\n";
  else
    cout<<"Second\n";

}

