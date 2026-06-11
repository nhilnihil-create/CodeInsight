

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;
ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M);
}

int main() {
  int m,k;
  cin >> m >> k;
  if(m==0){
    if (k==0){
      cout<<"0 0";
    }
    else cout<<"-1";
  }
  else if (m==1){
    if (k==0){
      cout<<"0 1 1 0";
    }
    else cout<<"-1";
  }
  else{
    ll temp=RepeatSquaring(2,m,INF);
    if (k>=temp)cout<<-1;
    else{
      cout<<k<<" ";
      rep(i,temp){
        if (i==k)continue;
        cout<<i<<" ";
      }
      cout<<k<<" ";
      rep(i,temp){
        if (temp-i-1==k)continue;
        cout<<temp-i-1<<" ";
      }


    }


  }
}
