#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;
#define int long long
//template
//main
signed main(){
  int N,M;cin>>N>>M;
  std::vector<int> blwh(N,0);
  std::vector<bool> used(N,0);
  std::vector<int> edge[N];
  for(int i=0;i<M;i++){
    int a,b;cin>>a>>b;a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  stack<int> st;
  st.push(0);blwh[0]=1;
  while(st.size()){
    int p=st.top();st.pop();
    if(used[p])continue;
    used[p]=true;
    for(int q:edge[p]){
      if(blwh[q]==blwh[p]*(-1))continue;
      if(blwh[q]==0){
        blwh[q]=blwh[p]*(-1);
        st.push(q);
      }
      else{
        cout<<N*(N-1)/2-M<<endl;
        return 0;
      }
    }
  }
  int B=0,H=0;
  for(int q:blwh)if(q==1)B++;
  H=N-B;
  cout<<B*H-M<<endl;
}
