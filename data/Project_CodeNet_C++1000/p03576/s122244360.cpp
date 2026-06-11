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
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll>> pos(N);
    vector<ll> x(N);
    vector<ll> y(N);
    for(ll i = 0; i < N; i++){
        ll tmpX,tmpY;
        cin >> tmpX >> tmpY;
        pos[i] = pair<ll,ll>(tmpX,tmpY);
        x[i] = tmpX;
        y[i] = tmpY;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    unsigned long long S = 1ull << 63;
    for(ll xs = 0; xs < N - 1; xs++){
        for(ll xt = xs + 1; xt < N; xt++){
            for(ll ys = 0; ys < N - 1; ys++){
                for(ll yt = ys + 1; yt < N; yt++){
                    ll count = 0;
                    for(ll i = 0; i < N; i++){
                        if((x[xs] <= pos[i].first) && (pos[i].first <= x[xt]) && (y[ys] <= pos[i].second) && (pos[i].second <= y[yt])){
                            count++;
                        }
                    }
                    if(count >= K){
                        S = min(S,(unsigned long long)(x[xt] - x[xs]) * (unsigned long long)(y[yt]- y[ys]));
                    }
                }
            }
        }
    }
    cout << S << endl;

}
