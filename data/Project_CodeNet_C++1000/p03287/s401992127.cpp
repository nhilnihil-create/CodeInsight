
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
   ll n, m;
   cin >> n >> m;
   vector<ll> a(n);
   rep(i,n) cin >> a.at(i);

   //累積和
   vector<ll> sum(n+1,0);
   rep(i,n){
       sum.at(i+1) = sum.at(i) + a.at(i);
   }
   //mapを使って累積和の剰余類ごとの個数を管理
   map<ll,ll> nums;
   rep(i,n+1) nums[(sum.at(i) % m)] ++;

   //集計処理
   ll res=0;
   for(auto it:nums){
       ll num=it.second;
       res += num*(num-1)/2;
   }

    cout << res << endl;

}