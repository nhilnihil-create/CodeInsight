#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  string s;
  cin >> s;
  int N = s.size();
  int cnt[3];
  fill(cnt, cnt+3, 0);
  for(int i=0;i<N;i++){
    if(s[i] == 'a') cnt[0]++;
    if(s[i] == 'b') cnt[1]++;
    if(s[i] == 'c') cnt[2]++;
  }

  sort(cnt, cnt+3);
  if(cnt[0] == cnt[1] && cnt[1] == cnt[2]) cout << "YES" << endl;
  else if(cnt[0] == cnt[1] && cnt[1] == cnt[2] - 1) cout << "YES" << endl;
  else if(cnt[0] == cnt[1] - 1 && cnt[1] == cnt[2]) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}