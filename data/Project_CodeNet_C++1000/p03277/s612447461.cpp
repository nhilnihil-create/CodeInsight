#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const long long N = 1e5 + 1;

ll n , a[N] , fen[2 * N] , b[N] , ans;

void update(int p , int val){
    for(int i = p ; i < 2 * N ; i += i & (-i)) fen[i] += val;
}

ll get(int p){
   ll res = 0;
   for(int i = p ; i ; i -= i & (-i)) res += fen[i];
   return res;
}

bool check(int mid){
    memset(fen , 0 , sizeof(fen));
    vector<ll> d(n + 1) , f(2 * n + 1);
    ll cnt = 0;
    for(int i = 1 ; i <= n ; i ++) d[i] = d[i - 1] + (a[i] >= b[mid]) , f[i] = 2 * d[i] - i;
    for(int i = 1 ; i <= n ; i ++){
      update(f[i - 1] + n , 1);
      cnt += get(f[i] + n);
    }
    return (2 * cnt >= n * (n + 1) / 2);
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i] , b[i] = a[i];
    sort(b + 1 , b + 1 + n);
    int l = 1 , r = n;
    while(l <= r){
      int mid = (l + r) / 2;
      if(check(mid)) l = mid + 1 , ans = b[mid];
      else r = mid - 1;
    }
    cout << ans << endl;
}
