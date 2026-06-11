#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+5;

int n;
ll bit[N] , a[N] , h[N] , resp;

void add(int pos , ll val){
  for( ; pos < N ; pos += pos&-pos) bit[pos] = max(bit[pos],val);
}

ll query(int pos){
  ll r = 0;
  for( ; pos ; pos -= pos&-pos) r = max(r,bit[pos]);
  return r;
}

int main(){
   cin >> n;

   for(int i = 1 ; i <= n ; i++) cin >> h[i];
   for(int i = 1 ; i <= n ; i++) cin >> a[i];
   for(int i = 1 ; i <= n ; i++) resp = max(resp,a[i]+query(h[i])) ,  add(h[i],a[i]+query(h[i]));

   cout << resp << "\n";

}
