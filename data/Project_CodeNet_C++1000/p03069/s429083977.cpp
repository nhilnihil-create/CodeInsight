  #include "bits/stdc++.h"
  using namespace std;

  int main()
  {
    ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    int c=0;
    for(int i=0;i<n;i++) {
      if(s[i]=='.') c++;
    }
    int ans = c;
    for(int i=0;i<n;i++) {
      if(s[i]=='#') c++;
      else c--;
      ans = min(ans, c);
    } 
    cout << ans << "\n";

    return 0;
  }