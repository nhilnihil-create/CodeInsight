#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int m,k;cin>>m>>k;
  int t = 0;
  rep(i, pow(2, m))if(i!=k)t^=i;
  if(t==k){
    rep(i, pow(2, m))if(i!=k)cout<<i<<' ';
    cout<<k<<' ';
    rrep(i, pow(2, m))if(i!=k)cout<<i<<' ';
    cout<<k;
    cout<<endl;
    return 0;
  }

  if(k>=pow(2, m)-1){ cout<<-1<<endl; return 0; }

  if(k==0){
    rep(i, pow(2,m))cout<<i<<' '<<i<<' ';
    return 0;
  }

  int mx = pow(2, m)-1;
  int mxb = mx^k;
  rep(i, pow(2, m))if(i!=mx && i!=mxb)cout<<i<<' ';
  cout<<mx<<' '<<mxb<<' ';
  rrep(i, pow(2, m))if(i!=mx && i!=mxb)cout<<i<<' ';
  cout<<mxb<<' '<<mx;
  cout<<endl;

//cout<<mx<<'*'<<mxb<<endl;
//  int t = 0;rep1(i, 120){t^=i; cout<<i<<' '<<t<<endl;}

  return 0;
}
