#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}


int main(){
  int Q; cin >> Q;
  auto table = prime_table(100005);
  vector<int> tab(100005,0);
  int cnt = 0;
  rep(i,100005){
    if (table[i] && table[(i+1)/2]) cnt++;
    tab[i] = cnt;
  }

  rep(q,Q){
    int l, r;
    cin >> l >> r;
    cout << tab[r+1]-tab[l-1] << endl;
  }


  // cout << fixed << setprecision(10);
  
  return 0;
}
