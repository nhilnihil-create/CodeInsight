#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,h,w;
  cin >> n >> h >> w;
  int ans = (n-h+1)*(n-w+1);
  cout << ans << endl;
  return 0;
}