#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;cin>>N;
    ll ah=0, an=0, aw=0;
    for(ll h=1; h<=3500; h++){
        for(ll n=1; n<= 3500; n++){
            ll l = h*n*N;
            ll bunshi = 4*h*n-n*N-N*h;
            // cerr<<l<<" "<<bunshi<<endl;
            if(bunshi == 0) continue;
            if(l%bunshi==0 && l/bunshi > 0){
                ah = h; an = n; aw = l/bunshi;
                break;
            }
        }
    }
    cout<<ah<<" "<<an<<" "<<aw<<endl;
}