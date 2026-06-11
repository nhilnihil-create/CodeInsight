// A

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

int main(){
  ll N;
  cin>>N;
  vector<tuple<ll,ll,ll>> t(N);
  for (int i(0);i<N;i++) {
    ll a,b;
    cin>>a>>b;
    t[i] = make_tuple(a+b,a,b);
  }
  sort(t.rbegin(),t.rend());
  ll ta(0),ao(0);
  for (int i(0);i<N;i++){
    if (i%2==0){
      ta += get<1>(t[i]);
    }else{
      ao += get<2>(t[i]);
    }
  }
  cout<< ta - ao << endl;
  return 0;
}
