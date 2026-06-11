#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int Count(int n){
  int cou = 0;
  for (int i=1; i<=n; i++){
    if (n%i == 0) cou++;
  }
  return cou;
}

int main(){
  int n; cin>>n;
  int ans = 0;
  for (int i=1; i<=n; i++){
    if (i%2==1){
      if (Count(i)==8) ans++;
    }
  }
  cout << ans << endl;
}