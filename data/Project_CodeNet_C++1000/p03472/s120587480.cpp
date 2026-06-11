#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
 ll n,h;
 cin >> n >> h;
 vector<ll>a(n),b(n);
 for(ll i=0;i<n;i++){
  cin >> a[i] >> b[i];
 }
 sort(a.begin(),a.end());
 sort(b.begin(),b.end());
 ll cnt=0;
 ll sum=0;
 for(ll i=n-1;i>=0;i--){
  if(a[n-1]>b[i]) break;
  sum+=b[i];
  cnt++;
  if(sum>=h) break;
 }
 h-=sum;
 if(h<=0){
  cout << cnt << endl;
  return 0;
 }
 if(h%a[n-1]!=0){
  cnt++;
 }
 cnt+=h/a[n-1];
 cout << cnt << endl;
}