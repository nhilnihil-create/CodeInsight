#include<bits/stdc++.h>
using namespace std;

int n;
string str;
vector<int> G[200005];
map< int , int > mp, mp2;


int solve(){
  int key=0;
  
  mp[key]=0;
  for(int i=0;i<n;i++){
    int ch = str[i]-'a';
    key ^= (1<<ch);
    if(mp.count(key)>0){
      G[ mp[key] ].push_back( i+1 );
      G[ mp2[key] ].push_back( i+1 );
      mp[key]=i+1;
    }else{
      mp[key]=i+1;
      mp2[key]=i+1;
    }
    

    for(int j=0;j<26;j++){
      int tmp=key;
      tmp^=(1<<j);
      if(mp.count(tmp)>0 ){
        G[ mp[tmp] ].push_back( i+1 );
      }
      if( mp2.count(tmp)>0) {
        G[ mp2[tmp] ].push_back( i+1 );
      }
    }
    
  }
  /*
  for(int i=0;i<=n;i++){
    cout<<i<<endl;
    for(int to:G[i]){
      cout<<to<<' ';
    }
    cout<<endl<<endl;
  }
  */
  const int INF = 1e9;
  vector<int> dp(n+1,INF);
  
  dp[0]=0;

  for(int i=0;i<n;i++){
    for(int j=0;j<(int)G[i].size();j++){
      int to=G[i][j];
      dp[to]=min(dp[to],dp[i]+1);
    }
    dp[i+1]=min(dp[i+1],dp[i]+1);
  }
  return dp[n];
}

int main(){
  while(  cin>>str ){

    n=str.size();
    for(int i=0;i<=n;i++)G[i].clear();
    mp.clear();
    
    cout<<solve()<<endl;
  }
  return 0;
}
