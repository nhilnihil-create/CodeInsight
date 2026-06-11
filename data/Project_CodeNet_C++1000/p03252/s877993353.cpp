#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

int main(void) {
    string s, t;
    cin >> s >> t;
    vector<ll> ss(27, 0), ts(27, 0);
    for(ll i = 0; i < s.length(); i++){
        char a = s[i], b = t[i];
        ss[a-97]++; ts[b-97]++;
    }
    sort(ss.begin(), ss.end());
    sort(ts.begin(), ts.end());
    bool ok = true;
    for(ll i = 0; i < 27; i++){
        if(ss[i]!=ts[i])
            ok = false;
    }
    if(ok==true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
