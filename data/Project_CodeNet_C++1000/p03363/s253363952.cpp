#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  long long n, csm=0, ans=0;
  map<long long, long long> mp;
  mp[0]++;
  cin >> n;
  for(int i=0;i<n;i++){
    long long a;
    cin >> a;
    csm += a;
    ans += mp[csm];
    mp[csm]++;
  }
  cout << ans << endl;
}

