#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;



int main(){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    for(int r=0;r<=3000;r++){
        for(int g=0;g<=3000;g++){
            int now = N - r*R - g*G;
            if(now%B==0&&now>=0)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
