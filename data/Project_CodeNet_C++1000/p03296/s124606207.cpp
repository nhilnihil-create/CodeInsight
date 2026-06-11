#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,a[10005];

int main() {
  cin >> n;
  rep(i,n)
  cin >> a[i];
  int ans=0;
  for(int i=1;i<n;i++){
     if(a[i]==a[i-1]){
      ans++; a[i]=-1;
    }
  }
  cout << ans << endl;
}