#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  int s;
  cin >> s;
  map<int, bool> mp;
  mp[s] = true;
  int cnt = 1;
  while(1){
    cnt++;
    if(s % 2) s = 3*s + 1;
    else s = s / 2;
    if(mp.count(s) && mp[s]) break;
    else mp[s] = true;
  }
  cout << cnt << endl;
}
    