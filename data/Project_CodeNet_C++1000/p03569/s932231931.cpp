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
  int n = s.size();
  int l = 0, r = n-1;
  int cnt = 0;
  while (l<r) {
    if (s[l]==s[r]) {
      l++, r--;
    }
    else {
      if (s[l]=='x') {
        l++, cnt++;
      }
      else if (s[r]=='x'){
        r--, cnt++;
      }
      else {
        cnt = -1;
        break;
      }
    }
  }
  cout << cnt << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}
