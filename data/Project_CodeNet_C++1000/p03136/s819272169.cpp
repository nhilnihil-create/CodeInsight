#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int l[n];
  rep(i,0,n) cin>>l[i];
  int ma=0;
  int sum=0;
  rep(i,0,n){
    ma=max(ma,l[i]);
    sum+=l[i];
  }
  if(sum-ma>ma) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}