#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <queue>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<int, int> P;

llint n, k;
string s;
llint Q;
llint D, DM, M;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  cin >> Q;
  for(int q = 0; q < Q; q++){
    cin >> k;
    D = DM = M = 0;
    llint ans = 0;

    for(int i = 0; i < n; i++){
      if(i >= k){
        if(s[i-k] == 'D') DM -= M, D--;
        else if(s[i-k] == 'M') M--;
      }
      if(s[i] == 'D') D++;
      else if(s[i] == 'M') DM += D, M++;
      else if(s[i] == 'C') ans += DM;
    }
    cout << ans << endl;
  }

  return 0;
}
