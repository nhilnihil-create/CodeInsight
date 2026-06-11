#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map>
#include <queue>
#include <functional>

using namespace std;
typedef long long int ll;
//考察が詰めきれず難しかった.
//クソコードにより添字地獄が発生して無限バグらせ死亡
int main(){

    ll N = 0;
    cin >> N;
    vector<ll > v(N, 0);
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        cin >> v[i];
        if(i == 0) continue;
        if(v[i] == v[i-1]){
            v[i] = 10000;
            ans++;
        }
    }

    cout << ans << endl;

} 