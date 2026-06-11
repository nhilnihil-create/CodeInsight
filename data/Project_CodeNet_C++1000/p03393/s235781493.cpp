#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  string s; cin >> s;
  vector<int> d(26);
  rep(i,s.size()) d[s[i]-'a']++;

  if (s.size()<26) {
    int j = find(all(d),0) - d.begin();
    char c = 'a'+j;
    cout << s+c << endl;
  }
  else if (s=="zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
  }
  else {
    for (int i=1;i<=25;i++){
      string ss = s.substr(26-i);
      sort(all(ss));
      auto itr = lower_bound(all(ss),s[25-i]);
      if (itr!=ss.end()) {
        char c = *itr;
        s.erase(25-i);
        cout << s + c << endl;
        break;
      }
    }
  }




  // cout << fixed << setprecision(10);
  
  return 0;
}
