#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    map<int,int> m;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        auto z = m.find(x);
        if(m.end()==z){
            m.insert(make_pair(x,1));
        }else{
            z->second++;
        }
    }
    int ans = 0;
    for(auto a:m){
        if(a.first < a.second){
            ans += a.second-a.first;
        }else if(a.first > a.second){
            ans += a.second;
        }
    }
    cout << ans;
}

