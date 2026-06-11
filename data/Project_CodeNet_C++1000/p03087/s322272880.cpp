#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;

ll
gcd(ll c, ll d)
{
  return d ? gcd(d, c % d) : c;
}

int
main() 
{
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<vector<int>> arr(q);
  rep(i, 0, q){
    int l, r; cin >> l >> r;
    arr[i].push_back(l);
    arr[i].push_back(r);
  }

  vector<int> acum(n + 1, 0);

  rep(i, 1, n){
    if(s[i - 1] == 'A' && s[i] == 'C'){
      acum[i] = acum[i - 1] + 1;
    } else {
      acum[i] = acum[i - 1];
    }
  }

  rep(i, 0, q){
    int l = arr[i][0];
    int r = arr[i][1];
    cout << acum[r - 1] - acum[l - 1] << endl;
  }





}

