#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    vector<ll> v;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
            v.push_back(n/i);
        }
    }
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 1) continue;
        ll tmp = v[i] - 1;
        if(n / tmp == n % tmp) ans += tmp;
    }
    cout<< ans;
}