#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  int N,b,st,res,butting,cnt,cP;
  
  cin >> N;
  vector<int> F(N);
  vector<vector<int> > P(N);

  REPI(N)
  {
    st = 0;
    REPJ(10)
    {
      cin >> b;
      st += b;
      st = st << 1;
    }
    F[i] = st >> 1;
  }

  REPI(N)
  {
    REPJ(11)
    {
      cin >> b;
      P[i].push_back(b);
    }
  }
  st = 1;
  
  while (st < 1024)
  {
    cP = 0;
    REPI(N)
    {
      butting = st & F[i];
      cnt = 0;
      while (butting > 0)
      {
        if(butting % 2 == 1)
          cnt++;
        
        butting /= 2;
      }
      cP += P[i][cnt];
    }
    if (st == 1)
    {
      res = cP;
    } else {
      res = max(res,cP);
    }    
    st++;
  }

  cout << res << endl;
  return 0;
}