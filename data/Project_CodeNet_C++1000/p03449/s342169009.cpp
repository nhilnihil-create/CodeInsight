#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  int s1[n+1],s2[n+1];
  s1[0]=0;
  s2[0]=0;
  rep(i,n){
    int s;
    cin>>s;
    s1[i+1]=s1[i]+s;
  }
  rep(i,n){
    int s;
    cin>>s;
    s2[i+1]=s2[i]+s;
  }
  int max_ans=0;
  rep(i,n){
    int ans=0;
    ans+=s1[i+1]-s1[0]+s2[n]-s2[i];
    max_ans=max(max_ans,ans);
  }
  cout<<max_ans<<endl;
}