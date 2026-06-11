#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int n;

void dfs(ll cur,int use,int &cnt){
  if(cur>n) return;
  if(use==0b111) cnt++;
  dfs(cur*10+7, use | 0b001 , cnt);
  dfs(cur*10+5, use | 0b010 , cnt);
  dfs(cur*10+3, use | 0b100 , cnt);
}

int main(){
  cin>>n;
  
  int res=0;
  dfs(0,0,res);  
  cout<<res<<endl;
  
  return 0;
}