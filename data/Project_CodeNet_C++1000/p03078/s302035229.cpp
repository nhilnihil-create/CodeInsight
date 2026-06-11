#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  for(int i=0; i<x; i++) cin >> a[i];
  for(int i=0; i<y; i++) cin >> b[i];
  for(int i=0; i<z; i++) cin >> c[i];
  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());
  sort(c.begin(), c.end(), greater<ll>());
  vector<ll> ans;
  for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
      for(int m=0; m<z; m++){
        if((i+1)*(j+1)*(m+1)<=k) ans.push_back(a[i]+b[j]+c[m]);
        else break;
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<ll>());
  for(int l=0; l<k; l++){
    cout << ans[l] << endl;
  }
  return 0;
}
