#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k,p;cin>>n>>k;
  double prob=0.0,tmp;
  for(ll i=1;i<=n;++i) {
    tmp=1.0/n;
    if(i>k-1) {prob+=tmp;continue;}
    p=i;
    while(p<k) {p*=2;tmp*=0.5;}
    prob+=tmp;
  }
  printf("%.10f",prob);
  return 0;
}