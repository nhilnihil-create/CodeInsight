#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N,M;
    cin >> N >> M;
    ll A[N];
    ll out = 0;
    rep(i,N){
        cin >> A[i];
        out += A[i];
    }
    sort(A,A+N);
    vector<pair<ll,ll>> v;
    rep(i,M){
        pair<ll,ll> p;
        cin >> p.second >> p.first;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    ll cnt = 0;
    rep(i,M){
        rep(j,v[M-1-i].second){
            for(ll k=cnt;k<N;k++){
                cnt++;
                if(A[k] < v[M-1-i].first){
                    A[k] = v[M-1-i].first;
                    break;
                }
            }
        }
        if(cnt==N) break;
    }
    out = 0;
    rep(i,N) out += A[i];
    cout << out << endl;
    return 0;
}
