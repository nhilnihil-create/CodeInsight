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
bool isBi(ll x){
    for(int i = 0; i <50; i++){
        if(x == (1ll << i)){
            return true;
        }
    }
    return false;
}

ll getMinBi(ll x){
    int i = 2;
    if(isBi(x)){
        return x;
    }
    while(true){
        if(i < x && x < i * 2){
             return i;
        }else{
            i *= 2;
        }
    }
}


int main() {
    ll N;
    cin >> N;
    map<ll,ll,greater<ll>> m = map<ll,ll,greater<ll>>();
    ll count = 0;
    for(int i = 0; i < N; i++){
        ll tmp;
        cin >> tmp;
        m[tmp]++;
    }
    auto begin = m.begin(), end = m.end();
    for (auto iter = begin; iter != end; iter++) {
        // first: key, second: value
        ll val = iter -> first;
        if(m[val] == 0){
            continue;
        }
        ll target = getMinBi(val) *2 - val;
        if(val == target){
            int del = m[val] / 2;
            count += del;
            m[val] -= del * 2;
        }else{
            int del = min(m[val],m[target]);
            m[val] -= del;
            m[target] -= del;
            count += del;
        }
        //cout << "key = " << iter->first << "\n";
        //cout << "value = " << iter->second << "\n";
    }
    cout << count << endl;


}
