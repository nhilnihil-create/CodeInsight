#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n,k; cin >> n >> k;
    vector<vector<int>> sushi(n);
    rep(i,n){
        int t,d; cin >> t >> d;
        t--;
        sushi[t].push_back(d);
    }

    vector<int> y0,y1;
    rep(i,n){
        if(sushi[i].size() == 0) continue;
        sort(ALL(sushi[i]));
        y1.push_back(sushi[i].back());  
        sushi[i].pop_back();
        y0.insert(y0.end(), ALL(sushi[i]));
    }
    sort(RALL(y0)); sort(RALL(y1));

    ll ans = 0;
    int Y = max(0, k-int(y0.size()));
    ll X = 0;
    rep(i,Y) X += y1[i];
    rep(i,k-Y) X += y0[i];
    while(true){        
        ans = max(ans, X + (ll)Y*Y);
        if(Y >= k || Y >= y1.size()) break;
        X += y1[Y];
        X -= y0[k-Y-1];
        Y++;
    }

    cout << ans << endl;
}
