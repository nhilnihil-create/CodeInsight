#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
int n;
cin>>n;
ll x;
cin>>x;
ll a[n];
rep(i,n){
    cin>>a[i];
}
sort(a,a+n);
int ans=0;
rep(i,n-1){
    if(x>=a[i]){
        x-=a[i];
        ans++;
    }
}
if(x==a[n-1]){
    ans++;
}
cout<<ans<<endl;
  return 0;
}
