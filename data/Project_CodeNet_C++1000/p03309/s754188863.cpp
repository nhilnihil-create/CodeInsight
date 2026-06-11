#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef vector<int,vector<int>> vec;
typedef pair<int,int> P;
#define REP(i,j,n) for (int i=j;i<(n);i++)
#define RREP(i,n) for (int i = n; 0<i;i--)
#define print(out) cout<< out  << "\n";
#define all(vec) vec.begin(),vec.end()
#define mod 1000000007
const int INF = 1e9;

int main(){
  ll N,a;cin>>N;
  vector<ll> vec(N);
  REP(i,0,N){
    cin>>a;
    vec[i]=a-i;
  }
  sort(all(vec));
  ll med=vec[vec.size()/2];
  ll ans=0;
  REP(i,0,N){
    ans+=abs(vec[i]-med);
  }
  print(ans)

}
