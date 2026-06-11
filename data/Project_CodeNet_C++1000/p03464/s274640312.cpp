#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll k;
  cin >> k;
  vector<ll> a(k);
  rep(i,k) cin >> a[i];
  ll lb=2;
  ll ub=2;
  ll mod=1;
  for(int i=k-1;i>=0;i--){
    ll maxcan = ub/a[i]*a[i];
    if(maxcan < lb){
      cout << -1 << endl;
      return 0;
    }
    else{      
        mod = a[i];
        lb=((lb/mod*mod==lb)?lb:(lb/mod+1)*mod);    
        ub= (ub/mod+1)*mod-1;

    }
  }
  cout << lb << " " << ub << endl;
  return 0;
    

}
