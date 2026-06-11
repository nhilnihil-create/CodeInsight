#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)

int main() {
  int n,h,w;cin >>n>>h>>w;
  int cnt =0;
  repi(i,0,n){
    int a,b;cin >>a>>b;
    if(a>=h&&b>=w) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
