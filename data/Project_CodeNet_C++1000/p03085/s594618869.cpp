#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  char b, ans;
  cin  >> b;
  if(b=='A')ans='T';
  else if(b=='T')ans='A';
  else if(b=='C')ans='G';
  else ans='C';

  cout << ans << endl;

  return 0;
}