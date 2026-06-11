#include <bits/stdc++.h>
using namespace std;

int main() {
  // a b c d
  // 1 2 2 1
  vector<int> cnt(4);
  for ( int i=0; i<3; i++ ) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    cnt[a]++;
    cnt[b]++;
  }
  sort(cnt.begin(),cnt.end());
  if ( cnt[0]==1&&cnt[2]==2&&cnt[0]==cnt[1]&&cnt[2]==cnt[3] ) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
