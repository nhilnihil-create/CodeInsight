#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=100100;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

ll gcd(ll a, ll b) {
  if (b==0) return a;
  else return gcd(b,a%b);
}
ll lcm(ll a, ll b) {
  ll g=gcd(a,b);
  return a/g*b;
}

int main(){
    ll N,M,L;
    string S,T;
    cin>>N>>M>>S>>T;
    L=lcm(N,M);
    ll a=L/M,b=L/N;
    ll k=lcm(a,b);

    for(ll i=0;i<=L/k;i++){
        if(S[a*i]!=T[b*i]){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<L<<endl;
}
