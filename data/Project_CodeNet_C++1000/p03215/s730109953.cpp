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
  int n,k;cin>>n>>k;
  vector<ll> a(n), aa, ca;
  rep(i, n)cin>>a[i];
  ca.push_back(0);
  rep(i, n) ca.push_back( ca.back() + a[i] );

  rep(i, n)for(int j=i+1; j<=n; j++) aa.push_back(ca[j]-ca[i]);

  sort(aa.begin(), aa.end());

  // search biggest bit satisfying numbers
  vector<ll>na;
  rrep(bit, 40){
    rrep(i, aa.size()) if( aa[i]>>bit & 1 )na.push_back(aa[i]);

    if(na.size()>=k)swap(aa, na);
    na.clear();
  }

  ll result=aa[0];
  rep(i, k)result = result&aa[i];
  cout<<result<<endl;

  return 0;
}
