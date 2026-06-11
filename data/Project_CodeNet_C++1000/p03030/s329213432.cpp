#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
#define reprange(i, a) for(int i : vector<int>a)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;
const ll INF=1LL << 60;
const ll MOD=1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  tuple<string, int, int> t[n];
  rep(i, n){
    string s;
    int m;
    cin >> s >> m;
    t[i]=make_tuple(s, 100-m, i+1);
  }

  sort(t, t+n);
  rep(i, n)cout << get<2>(t[i]) << endl;

  return 0;
}