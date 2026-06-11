#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll N,C;
    cin >> N >> C;
    vector<vector<pair<ll,ll>>> tab(C);
    for(int i = 0; i < C; i++){
        tab[i] = vector<pair<ll,ll>>(0);
    }
    for(int i = 0; i < N; i++){
        ll s,t,c;
        cin >> s >> t >>c;
        tab[c - 1].push_back(pair<ll,ll>(s, t));
    }

    int sum[200000];
    for(ll i = 0; i < 200000; i++){
        sum[i] = 0;
    }

    for(ll ci = 0; ci < C; ci++){
        int tmp[200000];
        for(int i = 0; i < 200000; i++){
            tmp[i] = 0;
        }
        for(ll i = 0; i < tab[ci].size(); i++){
            ll s = tab[ci][i].first;
            ll t = tab[ci][i].second;
            for(ll j = s; j <= t; j++){
                tmp[j] = 1;
            }
        }
        for(ll i = 0;i < 200000; i++){
            sum[i] += tmp[i];
        }
    }


    int M = 0;
    for(int i = 0; i < 200000; i++){
        M = max(M, sum[i]);
    }
    cout << M << endl;

}
