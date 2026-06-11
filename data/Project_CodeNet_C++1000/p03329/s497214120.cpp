#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int cnt=100000;
  rep(i,0,n+1){
    int c=i;
    int d=n-i;
    int cur=0;
    while(c>0){
      cur+=c%6;
      c/=6;
    }
    while(d>0){
      cur+=d%9;
      d/=9;
    }
    cnt=min(cnt,cur);
  }
  cout<<cnt<<endl;
}