#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  string s;
  cin>>n>>s;
  vector<int> black(n+1);
  vector<int> white(n+1);
  black[0]=0; white[0]=0;
  rep(i,n){
    if(s[i]=='#'){
      black[i+1]=black[i]+1;
      white[i+1]=white[i];
    }
    if(s[i]=='.'){
      black[i+1]=black[i];
      white[i+1]=white[i]+1;
    }
  }
  int ans=INT_MAX;
  rep(i,n+1){
    int now = black[i]-black[0] + white[n]-white[i];
    ans=min(ans,now); 
  }
  cout<<ans<<endl;
}

