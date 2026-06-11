#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()   //reverse
#define strall(v) (v).cbegin(),(v).cend() //const_itterator
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int INF = 1e9+5;
const ll LINF = 1e18;
ll n;

int main(){
  int n,k;
  cin >> n >> k;
  vector<ll> num(k,0);
  for(int i=1;i<=n;i++) num[i%k]++;//num[x] = kで割ってxあまる数が1以上N以下に何個あるか 
  ll res = 0;
  for(int a=0;a<k;a++){
    int b = (k-a) % k;
    int c = (k-a) % k;
    if((b+c) % k != 0) continue;
    res += num[a] * num[b] *num[c];
  }
  cout << res <<endl;
}
