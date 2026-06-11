#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int n,a,b,c;
vector<int>l;
int ans=1001001001;
void dfs(vector<int>A){
  if(A.size()==n){
    int now=1001001000;
    int w=0;
    int wc=0;
    int x=0;
    int xc=0;
    int y=0;
    int yc=0;
    
    rep(i,n){     
      if(A[i]==1){
        w+=l.at(i);
        wc++;
      }
      else if(A[i]==2){
        x+=l.at(i);
        xc++;
      }
      else if(A[i]==3){
        y+=l.at(i);
        yc++;
      }
    }
    if(wc>0&&xc>0&&yc>0){
      now=10*(wc+xc+yc-3)+abs(w-a)+abs(x-b)+abs(y-c);
    }
    
    ans=min(ans,now);
    
    return;
  }
  
  rep(v,4){
    A.push_back(v);
    dfs(A);
    A.pop_back();
  }
}
int main() {
  
  cin>>n>>a>>b>>c;
  l=vector<int>(n);
  rep(i,n){
    cin>>l.at(i);
  }
  dfs(vector<int>());   
  cout<<ans<<endl;
}

