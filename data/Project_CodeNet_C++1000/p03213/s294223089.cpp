//Problem: ABC114 D
//Progress:
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <cstring>
typedef long long int ll;
using namespace std;

const ll maxN = 101;

vector<ll> vlp;
bool is_prime[maxN];
vector<ll> spf(maxN);

map<ll, ll> mpl;

vector<ll> vans;

void sieve(){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for(ll i=2; i<maxN; i++){
        if(is_prime[i]){
            vlp.push_back(i);
            spf[i] = i;
        }
        for(ll j=0; j<(ll)vlp.size() && i*vlp[j] <= maxN && vlp[j] <= spf[i]; j++){
            is_prime[i*vlp[j]] = false;
            spf[i*vlp[j]] = vlp[j];
        }
    }
}

void solve(ll n){
    sieve();
    for(ll i=2; i<=n; i++){
        ll cop_i = i, j=0;
        while(cop_i != 1){
            while(cop_i%vlp[j] == 0){
                mpl[vlp[j]] += 1;
                cop_i /= vlp[j];
            }
            j++;
        }
    }
    for(map<ll, ll>::iterator it = mpl.begin(); it != mpl.end(); ++it){
        if(it->second >= 2)
            vans.push_back(it->second);
    }
    ll ans = 0;
    for(ll i=0; i<(ll)vans.size(); i++){
        for(ll j=i+1; j<(ll)vans.size(); j++){
            for(ll k=j+1; k<(ll)vans.size(); k++){
                if(vans[i] >= 4 && vans[j] >= 4 && vans[k] >= 2)
                    ans++;
                if(vans[i] >= 4 && vans[j] >= 2 && vans[k] >= 4)
                    ans++;
                if(vans[i] >= 2 && vans[j] >= 4 && vans[k] >= 4)
                    ans++;
            }
        }
    }
    for(ll i=0; i<(ll)vans.size(); i++){
        for(ll j=i+1; j<(ll)vans.size(); j++){
            if(vans[i] >= 24 && vans[j] >= 2)
                ans++;
            if(vans[i] >= 2 && vans[j] >= 24)
                ans++;
            if(vans[i] >= 14 && vans[j] >= 4)
                ans++;
            if(vans[i] >= 4 && vans[j] >= 14)
                ans++;
        }
    }
    for(ll i=0; i<(ll)vans.size(); i++){
        if(vans[i] >= 74)
            ans++;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    ll t;
    cin >> t;
    solve(t);
    return 0;
}