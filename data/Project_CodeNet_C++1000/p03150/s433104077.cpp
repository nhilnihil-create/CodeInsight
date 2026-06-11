#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    string key = "keyence";
    bool ok = false;
    rep(i,s.length()){
        rep(j,s.length()){
            rep(k,s.length()){
                auto t = s;
                if(k > s.length()-j) break;
                string a;
                t.erase(j,k);
                if(t == key) ok = true;
            }
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    cout << endl;
    return 0;
}
