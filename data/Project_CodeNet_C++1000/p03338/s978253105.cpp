#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  string s;
  cin>>n>>s;
  int ans=-1;
  rep(i,n){
    int now_ans=0;
    map<char,int> mp1;
    map<char,int> mp2;
    for(int j=0; j<=i; j++){
      mp1[s[j]]++;
    }
    for(int k=i+1; k<=n-1; k++){
      mp2[s[k]]++;
    }
    for(auto x : mp1){
      if(mp2[x.first]!=0){
        now_ans++;
      }
    }
    ans=max(ans,now_ans);
  }
  cout<<ans<<endl;
}