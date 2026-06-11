#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)
const ll mod = 1e9+7;

int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  rep(i,n){
    int x;
    cin >> x;
    mp[x]++;
  }
  int m;
  cin >> m;
  rep(i,m){
    int t;
    cin >> t;
    if (mp[t] > 0){
      mp[t]--;
    }else{
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
   

}
