#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  cin>>n;
  int cnt_a=0, cnt_b=0, cnt_ab=0;
  int ans=0;
  rep(i,n){
    string s;
    cin>>s;
    bool a=0, b=0;
    if(s[0]=='B') b=1;
    if(s[s.size()-1]=='A') a=1;
    if(a&b) cnt_ab++;
    else if(a) cnt_a++;
    else if(b) cnt_b++;
    rep(si,s.size()-1){
      if(s[si]=='A'&&s[si+1]=='B') ans++;
    }
  }
  if(cnt_a==0 && cnt_b==0) ans+=min(max(0,cnt_ab-1),n-1);
  else ans+=min(min(cnt_a,cnt_b)+cnt_ab,n-1);
  cout<<ans<<endl;
}
