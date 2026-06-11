#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
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
    map<ll,int> m;
    for(int i = 0;i < n;i++){
        ll a; cin >> a;
        auto x = m.find(a);
        if(x == m.end()){
            m.insert(make_pair(a,1));
        }else{
            x->second++;
        }
    }
    
    int y; cin >> y;
    string ans = "YES";
    for(int i = 0;i < y;i++){
        ll b; cin >> b;
        auto z = m.find(b);
        if(z == m.end()){
            ans = "NO";
            break;
        }else{
            z->second--;
            if(z->second == 0){
                m.erase(z);
            }
        }
    }
    cout << ans;
}

