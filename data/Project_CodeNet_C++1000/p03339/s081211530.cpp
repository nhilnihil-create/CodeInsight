#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int cur=0;
  rep(i,1,n){
    if(s[i]=='E'){
      cur++;
    }
  }
  int ans=cur;
  rep(i,1,n){
    if(s[i-1]=='W'){
      cur++;
    }
    if(s[i]=='E'){
      cur--;
    }
    ans=min(ans,cur);
  }
  cout<<ans<<endl;
}