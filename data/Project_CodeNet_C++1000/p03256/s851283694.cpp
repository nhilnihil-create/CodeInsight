// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
#define MAX_N 300000
bool ans = false;
vector<ll> G[MAX_N];
ll checked[MAX_N][2][2]={};
string s;
void solve(ll v,ll ch,ll cnt){
  if(ans) return;
  if(checked[v][ch][cnt]==2){
    return;
  }
  if(ch==0&&cnt==0&&checked[v][ch][cnt]==1){
    ans = true;
    return;
  }
  ll prech = ch,precnt = cnt;
  checked[v][ch][cnt] = 1;
  cnt++;
  if(cnt==2){
    cnt = 0;
    ch = (ch+1)%2;
  }
  for(auto nv:G[v]){
    if(ch==0&&s[nv]=='A'){
      solve(nv,ch,cnt);
    }
    if(ch==1&&s[nv]=='B'){
      solve(nv,ch,cnt);
    }
  }
  checked[v][prech][precnt] = 2;
}
signed main(){
  init_io();
  ll n,m;
  cin >> n >> m >> s;
  vector<ll> a(m),b(m);
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  for(int i=0;i<n;i++){
    if(s[i]=='A'){
      solve(i,0,0);
    }
  }
  if(ans) cout <<"Yes"<<endl;
  else cout <<"No"<<endl;
}
