#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n,h;
  cin>>n>>h;
  vector<int> a(n),b(n);
  rep(i,n){
    int A, B;
    cin>>A>>B;
    a[i]=A; b[i]=B;
  }
  sort(a.begin(),a.end(),greater<int>());
  sort(b.begin(),b.end(),greater<int>());
  int ans=0;
  rep(i,n){
    if(a[0] < b[i]){
      h-=b[i];
      ans++;
    }
    if(h<=0) break;
  }
  if(h>0){
    ans+=h/a[0];
    if(h%a[0]!=0) ans++;
  }
  cout<<ans<<endl;
}
