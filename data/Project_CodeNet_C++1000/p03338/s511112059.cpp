#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
#include <bitset>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> count(26);
  for(int i = 0;i < n;i++){
    count[s[i] - 'a']++;
  }
  //cout << count[0] << endl;
  ll res = 0;
  vector<ll> mae(26);
  for(int i = 0;i < 26;i++)mae[i] = 0;
  for(int i = 0;i < n;i++){
    ll now = 0;
      count[s[i] - 'a']--;
      mae[s[i] - 'a']++;
    for(int j = 0;j < 26;j++){
      if(mae[j] > 0 && count[j] > 0)now++;
    }  
    //cout << mae[0] << " " << count[0] << endl;
    res = max(res,now);
  }
  cout << res << endl;
}