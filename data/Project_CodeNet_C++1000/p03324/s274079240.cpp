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

int ja(int i){
  if(i%100!=0) return 0;
  return ja(i/100)+1;
}

int main(){
  int d,n;
  cin>>d>>n;
  int cnt=0;
  for(int i=1;;i++){
    if(ja(i)==d){
      cnt++;
    }
    if(cnt==n){
      cout<<i<<endl;
      return 0;
    }
  }
}