#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}

int main(){
    ll R, G, B, n;
    cin >> R >> G >> B >> n;
    ll ans = 0;
    for(ll i = 0; i*R <= n; i++){
        for(ll j = 0; i*R+j*G <= n; j++){
            if((n-i*R-j*G)%B == 0){
                //cout << i << " " << j << " " << n-i*R-j*G << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}