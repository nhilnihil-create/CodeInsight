#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD = 1e9 + 7;
const ll dx[4] = { -1,1,0,0 };
const ll dy[4] = { 0,0,-1,1 };
const ll MAX = 2e5 + 50 ;
const ll oo = 1e16;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
long long gcd(long long  a, long long  b) { return (b == 0 ? a : gcd(b, a % b)); }
ll n , m , q , ans; string s ;
vector < pair < char , char > > qr ;

bool solve(int ind , bool left){
    //cout << ind << "-> ";
    -- ind ;

    for(int i = 0 ; i < q && ind != -1 && ind != n; ++i){
        if(qr[i].f != s[ind]) continue;
        if(qr[i].s =='L') --ind;
        else ++ind;
    }
   // cout << ind << ' ' << left << '\n';
    if((ind != -1 && ind!= n) || (ind == -1 && !left) ||(ind == n && left))
            return false;

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q ;
    cin >> s ;
    for(int i = 0 ; i < q ; ++i){
        char a , b ;
        cin >> a >> b ;
        qr.pb({a , b});
    }

    ans = n ;

    int lo = 1 , hi = n ;
    int best = 0 ;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(solve(mid , true)){
            best = mid ;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    ans -= best;
    lo = 1 , hi = n;
    //cout << best << '\n';
    best = n + 1 ;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(solve(mid , false)){
            best = mid ;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    ans -= (n - best + 1);
    //cout << best << '\n';
    cout << ans << '\n';

     return 0;
}
