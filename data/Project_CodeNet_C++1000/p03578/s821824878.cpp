#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
typedef long long ll;
const int inf = 100100100;


int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  rep(i,n){
    int a;
    cin >> a;
    mp[a]++;
  }

  int m;
  cin >> m;
  rep(i,m){
    int a;
    cin >> a;
    if(mp[a]==0){
      cout << "NO" << endl;
      return 0;
    }else mp[a]--;
  }
  cout << "YES" << endl;
}
