#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef long double ld;

int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s[n], tmp;
  map<string,int> mp;
  char end;
  rep(i,n){
    cin >> tmp;
    mp[tmp]++;
    s[i] = tmp;
  }
  rep(i,n-1){
    end = s[i][s[i].length()-1];
    if(end != s[i+1][0]) {
      cout << "No" << endl;
      return 0;
    }
  }
  for(auto itr = mp.begin();itr != mp.end();++itr){
    if(itr->second > 1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}