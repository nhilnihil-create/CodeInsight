#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
  int n;
  cin>>n;
  int num[25];
  rep(i,0,25){
    num[i]=0;
  }
  rep(i,0,25){
    int cur=n;
    while(cur>0){
      cur/=prime[i];
      num[i]+=cur;
    }
  }
  int ans=0;
  rep(i,0,25){
    if(num[i]>=74) ans++;
  }
  rep(i,0,25){
    rep(j,0,25){
      if(i!=j){
        if(num[i]>=24 && num[j]>=2) ans++;
      }
    }
  }
  rep(i,0,25){
    rep(j,0,25){
      if(i!=j){
        if(num[i]>=14 && num[j]>=4) ans++;
      }
    }
  }
  rep(i,0,24){
    rep(j,i+1,25){
      rep(k,0,25){
        if(i!=k && j!=k){
          if(num[i]>=4 && num[j]>=4 && num[k]>=2) ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}