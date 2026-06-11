#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9+7LL;

int main() {
    ll N; cin >>N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);

    map<ll, ll> cnt;
    set<ll> s;
  
  	s.insert(0);
  	cnt[0] = 1;
    
    ll sum = 0;
    rep(i, N){
        sum += A.at(i);
        if(s.count(sum)){
            cnt.at(sum)++;
        }
        else{
            s.insert(sum);
            cnt[sum] = 1;
        }
    }

    ll ans = 0;
    for(auto value : s){
        ll n = cnt[value];
        ans += n*(n-1)/2;
    }

    cout << ans << endl;
}