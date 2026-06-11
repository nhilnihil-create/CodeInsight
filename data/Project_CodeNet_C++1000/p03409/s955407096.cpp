#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int n; cin >> n;
    vector<P> red; 
    vector<P> blue;
    rep(i,n){
        int a,b; cin >> a >> b;
        red.push_back(make_pair(a,b));
    }
    rep(i,n){
        int a,b; cin >> a >> b;
        blue.push_back(make_pair(a,b));
    }
    sort(red.begin(),red.end());
    sort(blue.begin(),blue.end());
    int ans = 0;
    bool not_use[n];
    rep(i,n) not_use[i] = true;
    rep(i,n){
        int bx = blue[i].first,by = blue[i].second;
        int now_y = -1;
        int id= -1;
        rep(j,n){
            if(!not_use[j]) continue;
            int rx = red[j].first,ry = red[j].second;
            if(rx < bx && ry < by && now_y < ry){
                id = j;
                now_y = ry;
            }
        }
        if(id != -1){
            ans++;
            not_use[id] = false;
        }
    }
    cout << ans << endl;
}