#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  string S,Srep;
  ll acnt,res = 0;

  cin >> S;

  REPI(S.size()-1)
  {
    if (S[i] == 'A')
      Srep += 'A';
    else if (S[i] == 'B' && S[i+1] == 'C')
    {
      Srep += 'D';
      i++;
    }else{
      Srep += S[i];
    }
  }

  acnt = 0;
  REPI(Srep.size ())
  {
    if (Srep[i] == 'A')
      acnt++;
    else if (Srep[i] == 'D')
      res += acnt;
    else
      acnt = 0;
  }

  cout << res << endl;
  
  return 0;
}