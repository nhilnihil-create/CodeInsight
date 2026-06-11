#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;


int main(){
  int n;  cin >> n;
  vector<ll> a(n), b(n);
  ll asum=0, bsum=0;

  for(int i=0; i<n; i++)  cin >> a.at(i);
  for(int i=0; i<n; i++)  cin >> b.at(i);
    
  
  vector<ll> dis(n);
  for(int i=0; i<n; i++){
    asum += a.at(i);
    bsum += b.at(i);
    dis.at(i) = a.at(i)-b.at(i);
  }
  sort(dis.begin(), dis.end(), greater<ll>());
  // for(int i=0; i<n; i++){
  //   cout << a[i] << b[i] << endl;
  // }
  
  ll j=0, next=0, cnt=-1;
  if(bsum<=asum){
    cnt=0;
    for(int i=0; i<n; i++){
      if(b[i]<=a[i]) continue;
      cnt += 1;
      while(next-(b[i]-a[i])<0){
        next += dis[j];
        cnt += 1; j += 1;
      }
      next -= (b[i]-a[i]);
    }
  }
  cout << cnt << endl;
}
