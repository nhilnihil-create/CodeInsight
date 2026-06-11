#include <iostream>
#include <string>

using namespace std;

int main()
{
  int l[26], r[26];
  string s;
  int tmp;
  int sum[100];
  int ans = 0;

  for ( int i = 0; i < 26; ++i ) l[i] = r[i] = -1;
  for ( int i = 0; i < 100; ++i ) sum[i] = 0;

  cin >> tmp;
  cin >> s;
  for ( int i = 0; i < s.size(); ++i ) {
    if ( l[s[i]-'a'] != -1 ) continue;

    l[s[i]-'a'] = i;
    for ( int j = i+1; j < s.size(); ++j ) {
      if ( s[i] == s[j] ) r[s[i]-'a'] = j;
    }
  }

  for ( int i = 0; i < 26; ++i ) {
    if ( r[i] != -1 ) {
      ++sum[l[i]];
      --sum[r[i]];
    }
  }

  for ( int i = 1; i < tmp; ++i ) sum[i] = sum[i-1]+sum[i];
  for ( int i = 0; i < tmp; ++i ) if ( ans < sum[i] ) ans = sum[i];

  cout << ans << endl;
}
