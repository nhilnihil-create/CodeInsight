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

ll score[65536];
ll a[17][17];

int main(){
  int n;cin>>n;
  rep(i, n)rep(j, n)cin>>a[i][j];

  rep(bit, 1<<n){
    ll s = 0;
    rep(i, n)rep(j, n){
      if(i==j)continue;
      if((bit>>i)%2==0 || (bit>>j)%2==0)continue;

      s += a[i][j];
    }
    score[bit]=s/2;
  }

//  rep(bit, 1<<n)cout<<score[bit]<<' ';cout<<endl;


  rep(bit1, 1<<n)for(int bit2=bit1; bit2>0; bit2 = (bit2-1)&bit1){
    if(bit1 == bit2)continue;
    score[bit1] = max<ll>(score[bit1], score[bit1-bit2] + score[bit2]);
  }
  int idx = (1<<n)-1;
  cout<<score[idx]<<endl;

  return 0;
}