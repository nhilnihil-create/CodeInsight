#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,h;
  cin>>n>>h;
  vector<int> a(n),b(n);
  int ma=0;
  rep(i,n){
    cin>>a[i]>>b[i];
    ma=max(ma,a[i]);
  }

  sort(b.begin(),b.end(),greater<int>());
  int res=n;
  rep(i,n){
    if(b[i]<ma){
      res=i;
      break;
    }
    h-=b[i];
    if(h<=0){
      cout<<i+1;
      return 0;
    }
  }
  
  int ans = min(res,n);
  ans += (h-1)/ma;
  cout << ans+1 << endl;
}