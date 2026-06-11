#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int n,cnt,ans=0;
 cin >> n;
 vector<int> a(n);
 rep(i,n) cin >> a[i];
 
 while(true){
  cnt=0;
  rep(i,n) if(a[i]%2==0) cnt++;
  if(cnt==n){
   ans++;
   rep(i,n) a[i] /= 2;
  }
  if(cnt<n) break;
 }
  
  cout << ans << endl;
  
}
   
    