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
  int k;cin>>k;
  vector<ll> a(k);
  rrep(i, k)cin>>a[i];

  ll minc=2, maxc=2;
  for(auto c: a){
    if(minc/c*c < minc && minc/c*c+c>maxc) { cout<<-1<<endl; return 0; }
    minc = (minc+c-1)/c*c;
    maxc = maxc/c*c+c-1;
//cout<<c<<' '; printf("%d %d\n", minc, maxc);
  }

  printf("%lld %lld\n", minc, maxc);

  return 0;
}
