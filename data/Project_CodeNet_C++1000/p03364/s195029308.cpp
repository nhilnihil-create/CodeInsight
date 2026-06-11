#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

using ll = long long;
using P = pair<ll,ll>;

#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = ((ll)(x) - 1); i >= 0; i--)

#define _upgrade ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

//ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
//ll lcm(ll x, ll y) {return x / gcd(x, y) * y;}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

const ll mod = 1e9 + 7;
const ll IMF = 1LL<<29;
const double PI = 3.14159265358979323846;


// ****************************************CODE***************************************//

int main(){
        _upgrade;
        int N;
        cin >> N;
        vector<string> s(N);
        for(int i = 0; i < N; i++) cin >> s[i];

        int ans = 0;
        for(int a = 0; a < N; a++){

                int flag = 1;
                for(int i = 0; i < N; i++){
                        for(int j = 0; j < N; j++){
                                flag &= (s[i][j] == s[j][i]);
                        }
                }
                ans += flag;

                for(int i = 0; i < N; i++){
                        s[i] = s[i].substr(1) + s[i].substr(0,1);
                }
        }

        cout << ans * N << endl;
        return 0;
}
