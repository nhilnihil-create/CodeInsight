#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;

const int mx=200010;
const ll mod=1e9+7;

int n, ans=0;
string a,b,c;

int main(){
  cin >> n >> a >> b >> c;
  for(int i=0; i<n; i++){
    if(a[i]==b[i] && b[i]==c[i]){continue;}
    if(a[i]==b[i] || b[i]==c[i] || a[i]==c[i]){ans++; continue;}
    ans += 2;  
  }

  cout << ans << endl;
  return 0;
}