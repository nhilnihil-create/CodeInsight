#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)


const long long INF = 1LL << 60;

int main()
{
   string s;
   ll ans=0;
   cin >> s;
   rep(i, s.size()) if(s[i]=='1') ans++;
   cout << ans << endl;
   return 0;
}
