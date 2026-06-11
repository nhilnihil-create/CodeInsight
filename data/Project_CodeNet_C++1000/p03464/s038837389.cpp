#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n;
  cin >> n;
  vector<ll>a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  reverse(a.begin(),a.end());
  ll b=2,e=2;
  ll remain1,remain2;
  for(int i=0; i<n; i++){
    remain1=(b-1)/a[i];
    remain2=e/a[i];
    if(a[i]*(remain1+1)>e){
      cout << -1 << endl;
      return 0;
    }
    b=a[i]*(remain1+1);
    e=a[i]*(remain2+1)-1;
    //cout << b << " " << e << endl;
    //cout << remain << endl;
  }
  cout << b << " " << e << endl;
}
  
  

  
  
  
