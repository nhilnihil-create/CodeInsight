

#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;




int main() {
  ll n,k;
  cin >> n >>k;
  vector<ll>v(n);
  vector<ll>l(n+1);
  vector<ll>r(n+1);


  l[0]=0;
  r[0]=0;
  rep(i,n){
    cin>>v[i];
    l[i+1]=l[i]+v[i];

  }
  rep(i,n){
    r[i+1]=r[i]+v[n-i-1];
  }
  ll A=-INF;

  rep(i,k+1){
    if(i>n)break;

    rep(j,i+1){
      ll ans=0;
  //    cout<<"i"<<i<<"j"<<j<<endl;
      ans+=l[i-j];
      ans+=r[j];
      //cout<<l[i-j]<<" "<<r[j]<<" "<<ans<<endl;
      vector<ll> a;
      rep(z,i-j)a.push_back(v[z]);
      rep(z,j)a.push_back(v[n-z-1]);
      sort(a.begin(),a.end());
//cout<<"siez"<<a.size()<<endl;
A=max(A,ans);
      rep(q,k-i){
        if (q>=i)break;
                  if (a[q]>0)break;
          ans-=a[q];
          A=max(A,ans);

        //  cout<<"ans"<<ans<<endl;

      }

    }
  }
  cout<<A;

}
