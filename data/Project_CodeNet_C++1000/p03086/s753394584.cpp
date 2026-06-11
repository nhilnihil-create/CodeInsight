#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int cnt=0, ans=0;
  rep(i ,(int)s.size()){
    if(s[i]!='A'&&s[i]!='T'&&s[i]!='C'&&s[i]!='G')cnt=0;
    else cnt++;
    if(ans<cnt)ans=cnt;
  }

  cout << ans << endl;

  return 0;
}