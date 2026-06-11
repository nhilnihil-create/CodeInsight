#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;
ll MOD = 2019;

int
main() 
{
  string S; cin >> S;
  int one = 0;
  int zero = 0;

  rep(i, 0, S.size()){
    if(S[i] == '0') zero++;
    else one++;
  }

  cout << min(one, zero) * 2 << endl;

}

