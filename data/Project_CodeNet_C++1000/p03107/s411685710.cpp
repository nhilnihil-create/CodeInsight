#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;

int main()
{
  string s;
  cin >> s;
  ll k=s.size();
  ll cnt_0 = 0,cnt_1 = 0;
  for (int i = 0; i < k;i++){
    if(s[i]=='0')
      cnt_0++;
      else
        cnt_1++;
     
      
  }
  cout << min(cnt_0, cnt_1) * 2 << endl;
}
