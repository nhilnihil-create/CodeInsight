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
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  ll ac = 0;
  ll bc = 0;
  ll res = 0;
  ll count = 0;
  for(int i = 0;i < n;i++){
    string s;
    cin >> s;
    bool now = false;
    if(s[0] == 'B')bc++,now = true;
    if(s[s.size() - 1] == 'A')ac++,now = true;
    if(now)count++;
    for(int j = 0;j < s.size() - 1;j++){
      if(s[j] == 'A' && s[j + 1] == 'B'){
        res++;
        j++;
      }
    }
  }
  if(count == 0)count++;
  res += min(min(ac,bc),count - 1);
  cout << res << endl;
}