#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int func(int x){
  if(x%100!=0) return 0;
  return func(x/100)+1;
}

int main(){
  string s;
  ll k;
  cin>>s>>k;
  int cnt=0;
  rep(i,len(s)){
    if(s[i]=='1') cnt++;
    if(s[i]!='1') break; 
  }
  if(k>cnt) cout<<s[cnt]<<endl;
  if(k<=cnt) cout<<1<<endl;
}