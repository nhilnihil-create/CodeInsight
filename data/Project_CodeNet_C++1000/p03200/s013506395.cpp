#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "O3"
#define rep(i,a,n) for(long long i=a; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
const double EPS = 1e-9;
const ll powll = 1LL<<1;

/*
while(!frag && cin >> a >>b, a|b)
*/

int main(void){
    string s; cin >> s;
    int w[s.size()] = {};
    for(int i= s.size()-1; i >=0; i--){
        if(s[i]=='W'){
            if(i==s.size()-1) w[i] = 1;
            else w[i] = w[i+1] + 1;
        }else{
            if(i==s.size()-1) w[i] = 0;
            else w[i] = w[i+1];
        }
    }
    ll ans = 0;
    rep(i,0,s.size()){
        if(s[i] == 'B'){
            ans += w[i];
        }
    }
    cout << ans << "\n";
}