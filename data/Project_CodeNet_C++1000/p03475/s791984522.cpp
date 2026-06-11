#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  int n;
  cin >> n;
  vi c(n),s(n),f(n);
  rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
  rep(i,n){
    int ans=0;
    for(int j=i;j<n-1;j++){
      if(ans<s[j]){
        ans=c[j]+s[j];
      }else{
        ans=c[j]+((ans-1)/f[j]+1)*f[j];
      }
    }
    cout << ans << "\n";
  }
  
  return 0;
}