#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  int n;  cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; i++)  cin >> a.at(i);
  int cnt=1, ans=0;
  for(int i=0; i<n-1; i++){
    if(a[i]==a[i+1]) cnt += 1;
    else{
      ans += cnt/2; cnt = 1;
    }
  }
  cout << ans+cnt/2 << endl;
}
