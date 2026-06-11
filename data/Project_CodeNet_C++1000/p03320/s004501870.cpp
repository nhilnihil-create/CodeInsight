#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

const ll MAX = 1e15;
const double INF = 1e18;

double f(ll x){
    ll sum = 0, tmp = x;
    while(tmp > 0){
        sum += (tmp % 10);
        tmp /= 10;
    }
    return (double)x / (double)sum;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll k; cin >> k;
    double minf = INF;
    ll tens[15];
    tens[0] = 1;
    for(int i=1;i<15;i++) tens[i] = tens[i-1] * 10;
    ll lower = 0;
    for(int i=0;i<12;i++) lower += 9 * tens[i];
    vector<ll> snuke;
    for(ll d=15;d>=3;d--){
        // upper 3
        for(ll i=9;i>=1;i--){
            for(ll j=9;j>=0;j--){
                for(ll k=9;k>=0;k--){
                    ll val = lower;
                    val += i * tens[d-1];
                    val += j * tens[d-2];
                    val += k * tens[d-3];
                    if(f(val) <= minf){
                        minf = f(val);
                        snuke.push_back(val);
                    }
                }
            }
        }
        if(d > 3) lower -= 9 * tens[d-4];
    }
    // d = 2
    for(ll i=9;i>=1;i--){
        for(ll j=9;j>=0;j--){
            ll val = 0;
            val += i * tens[1];
            val += j * tens[0];
            // cout << val << " " << f(val) << " " << minf << endl;
            if(f(val) <= minf){
                minf = f(val);
                snuke.push_back(val);
            }
        }
    }
    // d = 1
    for(ll i=9;i>=1;i--){
        ll val = i * tens[0];
        snuke.push_back(val);
    }
    sort(snuke.begin(), snuke.end());
    for(int i=0;i<k;i++) cout << snuke[i] << endl;
}