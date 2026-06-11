#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
using P = pair<ll, ll>;

int main(){
    ll n, p;
    cin >> n >> p;

    vector<P> bunkai;
    ll p2 = p;
    for(ll i = 2; i*i <= p; i++){
        if(p2 % i == 0){
            bunkai.push_back(make_pair(i, 0));
            while(p2 % i == 0){
                bunkai[bunkai.size()-1].second++;
                p2 /= i;
            }
        }
    }
    if(p2 > 1) bunkai.push_back(make_pair(p2, 1));

    ll ans = 1;
    for(auto data: bunkai){
        if(data.second / n >= 1){
            ll coans = data.first;
            for(ll i = 1; i < data.second/n; i++) coans *= data.first;
            ans *= coans;
        }
    }
    cout << ans << endl;
    return 0;
}