#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1, (i)>=0; (i)--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
ll const MOD = 1e9+7;
ll const INF = 1e18;
using namespace std;

class PrimeNumber{
public:
    int N;
    vector<ll> primetable;

    void MakeTable(int n){
        N = n;
        vector<bool> v(n+1, true);
        v[0] = false;
        v[1] = false;
        for(int i=2; i<=n; i++){
            if(v[i]){
                int j = i*2;
                while(j <= n){
                    v[j] = false;
                    j += i;
                }
            }
        }
        for(int i=0; i<=n; i++){
            if(v[i]){
                primetable.push_back(i);
            }
        }
    }

    bool is_prime(ll n){
        ll m = sqrt(n);
        for(ll i=2; i*i<=m; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }

    map<ll,int> factorization(ll n){
        map<ll,int> mp;
        for(ll i=2; i*i<=n; i++){
            while(n%i == 0){
                n /= i;
                mp[i]++;
            }
        }
        if(n > 1){
            mp[n]++;
        }
        return mp;
    }
};

int main(){
    ll n, p;
    cin >> n >> p;
    PrimeNumber PN;
    auto mp = PN.factorization(p);

    ll ans = 1;
    for(auto i : mp){
        ans *= max(1LL, (ll)pow(i.first, (i.second/n)));
    }
    cout << ans << endl;
    return 0;
}