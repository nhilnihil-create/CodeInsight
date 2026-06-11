#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n,k;
  cin >> n >> k;
  vector<P> s(n);
  rep(i,n){ cin>>s[i].S>>s[i].F; }
  sort(s.rbegin(),s.rend());
  ll ans=0;
  priority_queue<int,vector<int>,greater<int>> q;//daburi
  vector<bool> type(mx,false);
  ll cnt=0;
  
  for(int i=0; i<k; i++){
    ans += s[i].F;
    if(!type[s[i].S]){ cnt++; type[s[i].S]=true; }else{ q.push(s[i].F); }
  }
  ans += cnt*cnt;

  ll tmp=ans;
  for(int i=k; i<n; i++){
    if(cnt>=k){ break; }
    if(type[s[i].S]){ continue; }
    type[s[i].S]=true;
    tmp = tmp+(cnt+1)*(cnt+1)-cnt*cnt+s[i].F-q.top();
    ans = max(ans,tmp);
    cnt++;
    q.pop();
  }  
  
  cout << ans << endl; 
  return 0;
}
