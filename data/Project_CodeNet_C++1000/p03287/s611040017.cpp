#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, m, a[100009], cumsum=0;
  map<long long, long long> mp;
  cin >> n >> m;
  for(int i=0;i<n;i++)cin >> a[i];
  mp[0]++;
  long long ans=0;
  for(int i=0;i<n;i++){
    cumsum=(cumsum+a[i])%m;
    ans+=mp[cumsum];
    mp[cumsum]++;
  }
  cout << ans << endl;
}

