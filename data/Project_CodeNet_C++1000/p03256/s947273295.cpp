#include<bits/stdc++.h>
using namespace std;

int N,M;
string s;
int ac[200005];
int bc[200005];
vector<int> G[200005];

int main(){
  cin>>N>>M;
  cin>>s;
  for(int i=0;i<M;i++){
    int u,v;
    cin>>u>>v;
    u--,v--;
    G[u].push_back(v);
    G[v].push_back(u);

    if(s[v]=='A')ac[u]++;
    else bc[u]++;
    
    if(s[u]=='A')ac[v]++;
    else bc[v]++;
  }
  
  set<int> st;
  queue< int > Q;
  
  for(int i=0;i<N;i++){
    if( ac[i]==0 || bc[i]==0){
      Q.push(i);
      st.insert(i);
    }
  }
  while(!Q.empty()){
    int pos=Q.front();Q.pop();
    for(int to:G[pos]){
      if(s[pos]=='A')ac[to]--;
      else bc[to]--;
      if(ac[to]==0||bc[to]==0)
        if( st.count(to) == 0 ){
          Q.push(to);
          st.insert(to);
        }
    }
  }

  if(st.size() == N )cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}
