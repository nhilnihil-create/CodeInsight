#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s;
  int k;
  cin>>s>>k;
  int n=s.size();
  set<string> a;
  rep(i,0,k)
  rep(j,0,n-i){
    string t="";
    rep(l,j,j+i+1){
      t+=s[l];
    }
    a.insert(t);
  }
  int i=0;
  for(auto p:a){
    if(i==k-1){
      cout<<p<<endl;
      break;
    }
    i++;
  }
}