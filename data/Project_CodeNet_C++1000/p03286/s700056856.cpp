#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
  ll N;
  cin >> N;
  if(N==0){
    cout << 0 << endl;
    return 0;
  }
  string ans="";
  ll now=2;
  ll sum=0;
  rep(i,60){
    ll res=N-sum;
    ll rem=(res%now);
    if(rem<0)rem+=now;
    int r=i%2==0?1:-1;
    if(rem!=0){sum+=r*(now/2);ans+="1";}
    else{ans+="0";}
    now*=2;
  }
  reverse(ans.begin(),ans.end());
  bool beg=false;
  rep(i,ans.size()){
    if(ans[i]=='1')beg=true;
    if(beg)cout << ans[i];
  }
  cout << endl;

  return 0;
}