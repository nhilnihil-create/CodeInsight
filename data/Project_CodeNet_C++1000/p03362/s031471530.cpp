#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
bool isPrime[1000001];
void init(int mx) {
  isPrime[0] = isPrime[1] = false;
  for(int i=2;i<1000001;i++) isPrime[i]=true;
  for (int i = 2; i <= mx; i++) {
    if (isPrime[i]) {
      for (int j = 2; i * j <= mx; j++) isPrime[i * j] = false;
    }
  }
}
int main(void){
    ll n;
    cin>>n;
    init(100000);
    vector<ll> v;
    for(int i=2;i<=55555;i++) if(i%5==1&&isPrime[i]) v.push_back(i);
    for(int i=0;i<n;i++){
        cout<<v[i];
        if(i!=n-1) cout<<" ";
        else cout<<endl;
    }
}