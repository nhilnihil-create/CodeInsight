#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<pair<string, string>, int> cnt;

int main(){
  fastIO;
  int n;
  cin >> n;
  string t;
  cin >> t;
  string A, B;
  for(int i = 0 ; i < (1 << n); i ++ ){
    A.clear();
    B.clear();
    for(int j = n-1 ; j >= 0; j -- ){
      if(i & (1 << j)){
        A.push_back(t[n + j]);
      }
    }
    for(int j = 0 ; j < n; j ++ ){
      if(!(i & (1 << j))){
        B.push_back(t[n + j]);
      }
    }
    cnt[mp(A,B)] ++ ;
  }
  ll res = 0;
  for(int i = 0 ; i < (1 << n); i ++ ){
    A.clear();
    B.clear();
    for(int j = 0 ; j < n ; j ++ ){
      if(i & (1 << j)){
        A.push_back(t[j]);
      }
    }
    for(int j = n - 1; j >= 0 ; j -- ){
      if(!(i & (1 << j))){
        B.push_back(t[j]);
      }
    }
    res += cnt[mp(A,B)];
  }
  cout << res << "\n";
  return 0;
}