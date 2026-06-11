#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int main(){
   ll n, h; cin >> n >> h;
   vector<pair<ll,ll>> a(n);
   vector<pair<ll,ll>> b(n);
   rep(i, n){
       cin >> a[i].first >> a[i].second;
       b[i].first = a[i].second;
       b[i].second = a[i].first;
   }
   sort(a.begin(), a.end(), greater<>());
   sort(b.begin(), b.end(), greater<>());
   vector<ll> use;
   ll sum = 0;
   ll count = 0;
   rep(i, n){
       if(a[0].first < b[i].first){
           use.push_back(b[i].first);
           sum += b[i].first;
           count++;
           if(sum >= h){
               cout << count << endl;
               return 0;
           }
       }
    }
    count += (h - sum + a[0].first - 1) / a[0].first;
    cout << count << endl;
}