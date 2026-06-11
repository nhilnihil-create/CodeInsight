#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n, ans = 0, m;
  scanf("%d", &n);
  string s;
  vector<int> cnt(3, 0);
  for (int i = 0; i < n; i++){
    cin >> s;
    m = s.length();
    for (int j = 0; j < m - 1; j++)
      if (s[j] == 'A' && s[j + 1] == 'B') ans++;
    if (s[0] == 'B' && s[m - 1] == 'A') cnt[0]++;
    else if (s[0] == 'B') cnt[1]++;
    else if (s[m - 1] == 'A') cnt[2]++;
  }
  // B A A A A BA BA BA BA BA
  // B A BA -> ABAB
  if (!cnt[0]){
    printf("%d\n", ans + min(cnt[1], cnt[2]));
  }else{
    ans += cnt[0] - 1 + (cnt[1] >= 1) + (cnt[2] >= 1);
    ans += max(0, min(cnt[1] - 1, cnt[2] - 1));
    printf("%d\n", ans);
  }
  return 0;
}
