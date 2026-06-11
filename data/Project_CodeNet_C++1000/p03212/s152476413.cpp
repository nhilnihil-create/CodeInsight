#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

bool isOK(int x){
  bool a=0,b=0,c=0;
  while(x>0){
    if(x%10==3) a=1;
    if(x%10==5) b=1;
    if(x%10==7) c=1;
    x/=10;
  }
  if(a&&b&&c) return 1;
  else return 0;
}

int u[]={3,5,7};

void dfs(int n, int d, vector<int> &vec){
  if(d==10) return;
  vec.push_back(n);
  for(int tmp=0; tmp<3; tmp++){
    dfs(n*10+u[tmp],d+1,vec);
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> vec,num;
  dfs(3,1,vec);
  dfs(5,1,vec);
  dfs(7,1,vec);
  sort(vec.begin(),vec.end());
  for(auto x : vec){
    if(isOK(x)) num.push_back(x);
  }
  int ans=0;
  for(auto x : num){
    if(x > n) continue;
    ans++;
  }
  cout<<ans<<endl;
}

