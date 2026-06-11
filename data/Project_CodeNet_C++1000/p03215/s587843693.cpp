#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> s(N+1);
    for(int i=0; i<N; i++){
        ll tmp;
        cin >> tmp;
        s[i+1] = s[i] + tmp;
    }

    vector<ll> a(N*(N+1)/2);
    int k = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<=N; j++){
            a[k] = s[j] - s[i];
            k++;
        }
    }
    sort(a.begin(), a.end());

    ll l = 1;
    while(l < a.back()) l <<= 1;

    ll ans = 0;
    while(l > 0){
        l >>= 1;
        auto itr = lower_bound(a.begin(), a.end(), l);
        if(distance(itr, a.end()) >= K){
            ans += l;
            for(auto& x: a){
                x = max((ll)0, x-l);
            }
        }
        else{
            for(auto& x: a){
                if(x >= l) x -= l;
            }
        }
        sort(a.begin(), a.end());
    }

    cout << ans << endl;
}