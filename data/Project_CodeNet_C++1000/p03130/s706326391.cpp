#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  map<int, int>m;
  int maxn=0;
  rep(i,3)rep(i,2){
    int t;cin>>t;
    m[t]++;
    maxn=max(maxn, m[t]);
  }

  if(m.size()==4 && maxn==2) cout<<"YES";
  else cout<<"NO";

  return 0;
}