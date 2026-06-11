#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

int main(){
    string s;cin >> s;
    ll ans = 0;
    ll mid = 0;
    ll p = s.size();
    for(int i = 0;i < p;i++){
        if(s[i] == 'A' || s[i] == 'G' || s[i] == 'C' || s[i] == 'T'){
            mid++;
            continue;
        }
        else{
            ans = max(ans, mid);
            mid = 0;
        }
    }
    ans = max(ans,mid);
    cout << ans << endl;
}