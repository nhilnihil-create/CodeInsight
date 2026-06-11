#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll A,B,Q;
  cin>>A>>B>>Q;
  vector<ll> shr(A);
  vector<ll> tem(B);
  vector<ll> que(Q);
  for(ll i = 0LL; i < A; i++) cin>>shr[i];
  for(ll i = 0LL; i < B; i++) cin>>tem[i];
  for(ll i = 0LL; i < Q; i++) cin>>que[i];
  vector<ll> nt(A);
  vector<ll> ns(B);
  ll k = 0LL;
  for(ll i = 0LL; i < A; i++) {
    auto a = lower_bound(tem.begin(),tem.end(),shr[i]);
    if(a==tem.end())nt[i]=abs(shr[i]-tem[B-1LL]);
    else if(a==tem.begin())nt[i]=abs(shr[i]-tem[0]);
    else nt[i]=min(abs(shr[i]-*a),abs(shr[i]-*(a-1)));
  }
  for(ll i = 0LL; i < B; i++) {
    auto a = lower_bound(shr.begin(),shr.end(),tem[i]);
    if(a==shr.end())ns[i]=abs(tem[i]-shr[A-1LL]);
    else if(a==shr.begin())ns[i]=abs(tem[i]-shr[0]);
    else ns[i]=min(abs(tem[i]-*a),abs(tem[i]-*(a-1)));
  }
  for(auto x:que){
    ll pasa=0LL,pasb=0LL;
    auto a = lower_bound(tem.begin(),tem.end(),x);
    if(a==tem.end()){
      pasa+=abs(x-tem[B-1LL]);
      pasa+=ns[B-1LL];
    }
    else if(a==tem.begin()){
      pasa+=abs(x-tem[0]);
      pasa+=ns[0];
    }
    else {
      pasa+=min(abs(x-*a)+ns[a-tem.begin()],abs(x-*(a-1))+ns[a-1-tem.begin()]);
    }
    auto b = lower_bound(shr.begin(),shr.end(),x);
    if(b==shr.end()){
      pasb+=abs(x-shr[A-1LL]);
      pasb+=nt[A-1LL];
    }
    else if(b==shr.begin()){
      pasb+=abs(x-shr[0LL]);
      pasb+=nt[0];
    }
    else {
      pasb+=min(abs(x-*b)+nt[b-shr.begin()],abs(x-*(b-1))+nt[b-1-shr.begin()]);
    }
    cout<<min(pasa,pasb)<<endl;
  }
}