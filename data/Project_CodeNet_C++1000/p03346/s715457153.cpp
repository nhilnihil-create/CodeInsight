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
  ll n,p;cin>>n;
  lvector Q(n,0),checked(n,0);
  rep(i,n) {cin>>p;Q[p-1]=i;}
  ll prev=-1,l=0,l_=0;
  rep(i,n) {
    if(prev>Q[i]) l_=0;
    l_++;
    prev=Q[i];
    l=max(l,l_); 
  }
  print(n-l);
  return 0;
}