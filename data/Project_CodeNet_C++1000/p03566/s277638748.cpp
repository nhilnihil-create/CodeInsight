#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    cin >> n;

    pair<ld, ld> seq[n];
    rep(i, 0, n){
        cin >> seq[i].first;
    }
    rep(i, 0, n){
        cin >> seq[i].second;
    }

    ll max_time = 0;
    rep(i, 0, n){
        max_time += seq[i].first * 2;
    }

    ld v[max_time + 1];
    fill(v, v + max_time + 1, 100000000);
    ll nt = 0;
    rep(i, 0, n){
        rep(j, 0, seq[i].first){
            ll t1 = nt + j * 2;
            ll t2 = nt + j * 2 + 1;
            v[t1] = min(v[t1], seq[i].second);
            v[t2] = min(v[t2], seq[i].second);
        }
        nt += seq[i].first * 2;
        v[nt] = min(v[nt], seq[i].second);
    }

    v[0] = 0.0;
    v[max_time] = 0.0;

    rep(i, 0, max_time + 1){
        v[i + 1] = min(v[i + 1], v[i] + 0.5);
    }
    rrep(i, max_time + 1, 0){
        v[i] = min(v[i], v[i + 1] + 0.5);
    }


    ld dist = 0;
    rep(i, 0, max_time){
        dist += (v[i] + v[i + 1]) * 0.5 / 2.0;
    }
    printf("%.10Lf\n", dist);

}
