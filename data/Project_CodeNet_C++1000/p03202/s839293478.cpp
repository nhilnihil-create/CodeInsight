#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
// pll pp; -> (pp.first,pp.second)
// vector<vl> pp(n,vl(2)); sort(pp.begin(),pp.end(),[](vl a,vl b){return a[0]<b[0];});

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define RREP(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define DEBUG(x) cout << #x << ": " << x << endl

ll n;
ll a[200001];
bool isOK(ll m){
  stack<pii> st;
  REP(i,n){
    // a[i+1]>a[i]なら末尾に1をa[i+1]-a[i]個足すだけ
    if(a[i+1]>a[i]){
      st.push(make_pair(1,a[i+1]-a[i]));
      continue;
    }
    // pcは削る文字数
    ll pc = a[i] - a[i+1];
    // 文字列の長さをa[i+1]に揃える
    while(!st.empty() && pc>0){
      pii tp = st.top();
      st.pop();
      if(pc<tp.second){
        st.push(make_pair(tp.first,tp.second-pc));
      }
      pc = max(pc-tp.second,(ll)0);
    }

    // 以降は+1を試みる（可能ならする）操作

    // 末尾にmが並んでる場合全部popして、popした桁数をmisslenに記録しておく
    ll misslen = 0;
    while(!st.empty() && st.top().first>=m){
      misslen += st.top().second;
      st.pop();
    }
    // 全ての桁がmだった場合は+1出来ないので失敗
    if(st.empty()) return false;

    // この時点で+1可能なことは確定しているので、+1の操作を行う
    // mより小さい、最も後ろにある文字を+1する
    pii tp = st.top();
    st.pop();
    if(tp.second>1) st.push(make_pair(tp.first,tp.second-1));
    st.push(make_pair(tp.first+1,1));
    // popした桁を1で補完する
    if(misslen>0) st.push(make_pair(1,misslen));
  }
  return true;
}
int main() {
  cin >> n;
  REP(i,n) cin >> a[i+1];

  // めぐる式二分探索（今回は解の値域が1以上n以下で、nはOKが確定）
  ll ok=n,ng=0;
  while(abs(ok-ng)>1){
    ll m = (ok+ng)/2;
    if(isOK(m)) ok = m;
    else ng = m;
  }

  cout << ok << endl;
  return 0;
}
