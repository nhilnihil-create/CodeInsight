#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  if(s.back()=='F') s.push_back('T');
  int x,y,cnt=0,now=0,a,b;
  cin>>x>>y;
  vector<vector<bool>> dp1(8010,vector<bool>(20010,false));
  vector<vector<bool>> dp2(8010,vector<bool>(20010,false));
  dp1[0][10000]=true;
  dp2[0][10000]=true;
  rep(i,len(s)){
    if(s[i]=='F') now++;
    else if(s[i]=='T'){
      cnt++;
      if(cnt==1){
        dp1[cnt][10000+now]=true;
        a=1;
      }else if(cnt%2==0){
        rep(j,20001) dp2[cnt/2][j]=dp2[cnt/2-1][max(0ll,j-now)]|dp2[cnt/2-1][min(20000ll,j+now)];
        b=cnt/2;
      }else{
        rep(j,20001) dp1[cnt/2+1][j]=dp1[cnt/2][max(0ll,j-now)]|dp1[cnt/2][min(20000ll,j+now)];
        a=cnt/2+1;
      }
      now=0;
    }
  }
  if(dp1[a][10000+x] && dp2[b][10000+y]) cout<<"Yes"<<endl;
  else cout<<"No"<<endl; 
}