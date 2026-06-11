#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;

ll digitFirst(ll x){
  ll first = 0;
  vector<ll> digit;
  while(x>0){
   	first = x%10;
    digit.push_back(first);
    x/= 10;
  }
  for(int i = 0; i< digit.size()-1;i++){
    if(digit[i] != 9){
      first -= 1;
      break;
    }
  }
  return first;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >>s;
  int l = s.length();
  int c = s[0] - '0';
  int ans;
  for(int i = 1; i < l;i++){
   if(s[i] != '9'){
     ans = c + 9 * (l - 1) - 1;
     cout << ans << endl;
     return 0;
   }
  }
  ans = c + 9 * (l - 1);
  cout << ans << endl;
  return 0;
}