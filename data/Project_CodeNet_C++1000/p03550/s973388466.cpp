#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n,z,w;
  cin>>n>>z>>w;
  int a[20005];
  rep(i,n) cin>>a[i];
  if(n-2>=0) cout<<max(abs(w-a[n-1]),abs(a[n-1]-a[n-2]));
  else cout<<abs(w-a[n-1])<<endl;
  return 0;
}

