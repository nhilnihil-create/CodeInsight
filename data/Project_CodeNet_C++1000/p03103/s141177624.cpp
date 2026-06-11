#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
using ll =long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> vp(N);
    ll a, b;
    for(ll i=0; i<N; i++){
        cin >> a >> b;
        vp.at(i) = make_pair(a, b);
    }

    sort(vp.begin(), vp.end());

    ll sum = 0;
    ll kosu = 0;
    for(auto c : vp){
        if(kosu + c.second <= M){
            kosu += c.second;
            sum += c.first * c.second;
        }
        else{
            sum += (M-(kosu))*c.first;
            break;
        }
    }
    cout << sum << endl;
}
