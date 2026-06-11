#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n;
  cin >> n;
  vint time(13);
  vint D(n);
  time[0]++;
  rep(i,0,n){
    cin >> D[i];
    time[D[i]]++;
  }
  if(time[0] >= 2 || time[12] >= 2){
    cout << 0 << endl;
    return 0;
  }
  rep(i,1,12){
    if(time[i] >= 3){
      cout << 0 << endl;
      return 0;
    }
  }
  int ans = 0;
  for(int i = 0;i < (1 << 12);i++){
    vint judge(13);
    rep(j,0,13){
      if(i>>j&1) judge[j] = 1;
    }
    vint V;
    rep(j,0,13){
      if(time[j] == 2){
        V.push_back(j);
        V.push_back(24-j);
      }
      else if(time[j] == 1){
        if(judge[j] == 0){
          V.push_back(j);
        }
        else{
          V.push_back(24-j);
        }
      }
    }
    int tmp = INF;
    // rep(j,0,V.size()) cout << V[j] << " ";
    // cout << endl;
    rep(s,0,V.size()-1){
      rep(j,s+1,V.size()){
        tmp = min(tmp,abs(V[s] - V[j]));
        tmp = min(tmp,24 - abs(V[s]-V[j]));
      }
    }
    ans = max(ans,tmp);
  }
  cout << ans << endl;
}