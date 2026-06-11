#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

int main(){
    ll n; cin >> n;
    ll x = 1; ll y = 2;
    bool ok = false;
    while(x*y <= 2*n){
        if(x*y == 2*n){
            ok = true;
            break;
        }
        x++; y++;
    }
    if(!ok){
        cout<<"No"<<endl;
        return 0;
    }else cout<<"Yes"<<endl;

    vector<vector<ll>> sets(y);
    rep(i,0,y) sets[i].push_back(x);
    sets[0].push_back(1); sets[1].push_back(1); 
    ll now = 1; ll stop = 3; ll step = 3; ll h2 = 2;
    while(now < n){
        ll h1 = 0;
        while(now < stop){
            now++;
            sets[h1].push_back(now);
            sets[h2].push_back(now);
            h1++;
        }
        h2++;
        stop+=step; step++;
    }

    cout<<y<<endl;
    rep(i,0,y){
        rep(j,0,x+1){
            cout<<sets[i][j]<<" ";
        }
        cout<<endl;
    }
    

}