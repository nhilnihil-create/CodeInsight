#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> card;
vector<vector<ll>> ans;

ll calc(ll x, ll y){
    if(ans.at(x).at(y) != -1){
        return ans.at(x).at(y);
    }

    ll ret;
    if(x > y){
        if(y == 0){
            ret = abs(card.at(x) - card.at(y));
        }else if(x > y + 1){
            ret = calc(y + 1, y);
        }else{
            // x == y + 1 and y > 0
            ret = calc(0, y);
            for(int i = 1; i < y; ++i){
                ret = max(ret, calc(i, y));
            }
        }
    }else{
        if(x == 0){
            ret = abs(card.at(x) - card.at(y));
        }else if(y > x + 1){
            ret = calc(x, x + 1);
        }else{
            // x + 1 == y and x > 0
            ret = calc(x, 0);
            for(int i = 1; i < x; ++i){
                ret = min(ret, calc(x, i));
            }
        }
    }
    ans.at(x).at(y) = ret;
    return ret;
}

int main(){
    ll n, z, w;
    cin >> n >> z >> w;
    card.resize(n + 2);
    for(int i = 0; i < n; ++i){
        cin >> card.at(n - 1 - i);
    }
    card.at(n) = w;
    card.at(n + 1) = z;
    ans.resize(n + 2, vector<ll>(n + 2, -1));
    cout << calc(n + 1, n) << endl;
    return 0;
}