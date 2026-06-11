#include<bits/stdc++.h>
#define REP(i,x,y) for(ll i=x; i<=y; i++)
#define BIT(t) ((long long 1) << t)
#define PER(i,y,x) for(ll i=y; i>=x; i--)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define SIZE(v) ll(v.size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
typedef long long ll;

// int main(){
//         ll n;
//         cin >> n;
//         vll r(n), c(n);
//         REP(i,0,n-1){
//                 cin >> r[i] >> c[i];
//         }
//         vvll dp(110, vll(110, 1e9));
//         REP(i,0,n-1){
//                 dp[i][i] = 0;
//         }
//         REP(i,1,n-1){
//                 for(ll j = 0;j+i < n;j++){
//                         ll k = i+j;
//                         ll tmp = 1e9;
//                         REP(l,j,k-1){
//                                 tmp = min(tmp, dp[j][l] + dp[l+1][k] + r[j]*c[l]*c[k]);
//                         }
//                         dp[j][k] = tmp;
//                 }
//         }
//         cout << dp[0][n-1] << endl;
// }

bool f(vll& v){
        ll ttl = 0;
        for(auto x:v){
                ttl += x;
        }
        if(ttl % 2){
                return false;
        }
        ttl /= 2;
        bitset<8000> b = 1;
        REP(i,0,v.size() - 1){
                b = b | (b << v[i]);
        }
        if(b[ttl]){
                return true;
        }else{
                return false;
        }
}

int main(){
        string s;
        cin >> s;
        s+='T';
        ll x,y;
        cin >> x >> y;
        vll numf[2];
        bool flag = 0;
        ll cur = 0;
        ll cnt = 0;
        REP(i,0,s.size()-1){
                
                if(s[i] == 'T'){
                        if(!flag){
                                x -= cnt;
                        }else{
                                numf[cur].push_back(cnt);
                        }
                        cnt = 0;
                        cur = (cur + 1) % 2;
                        flag = 1;
                }else{
                        cnt++;
                }
        }
        numf[0].push_back(abs(x));
        numf[1].push_back(abs(y));
        if(f(numf[0]) && f(numf[1])){
                cout << "Yes" << endl;
        }else{
                cout << "No" << endl;
        }
        for(auto x:numf[0]){
                //cout << x << " ";
        }
        for(auto x:numf[1]){
                //cout << x << " ";
        }
}