#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    int now = 0;
    int xx = 0;
    int yy = 0;
    bool ok = 1;
    rep(i,n){
        int t,x,y;
        cin >> t >> x >> y;
        int dis = abs(xx-x) + abs(yy-y);
        if(dis>t-now){
            if(ok) cout << "No" << endl;
            ok = 0;
        }else{
            if(dis%2 != (t-now)%2){
                if(ok) cout << "No" << endl;
                ok = 0;
            }
        }
        now = t; xx = x; yy = y;
    }
    if(ok) cout << "Yes" << endl;
    return 0;
}