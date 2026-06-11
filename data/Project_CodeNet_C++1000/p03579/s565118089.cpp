#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

int main(){
  int n,m;cin>>n>>m;
  vector<vector<int>> G(n);
  rep(i,m){
    int a,b;cin>>a>>b;
    --a;--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int reached[n]={};
  stack<int> st;
  st.push(0);
  reached[0]=1;
  int ctr=0;
  bool flag=1;
  while(!st.empty()){
    if(!flag)break;
    int t=st.top();
    st.pop();
    for(auto au:G[t]){
      int color=(2-reached[t])+1;
      if(reached[au]==0){
        reached[au]=color;
        st.push(au);
      }
      else{
        if(color!=reached[au]){
          flag=0;
          break;
        }
      }
    }
  }
  if(!flag)cout<<1ll*n*(n-1)/2-m<<endl;
  else{
    int b=0;
    rep(i,n){
      if(reached[i]==1)++b;
    }
    cout<<1ll*b*(n-b)-m<<endl;
  }
}
          


    



  
