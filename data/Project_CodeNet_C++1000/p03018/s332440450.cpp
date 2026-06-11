#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

string s,s2;

int main() {
    cin >> s;
    ll cnta = 0,ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'A') cnta++;
        else if(s[i] == 'B' && s[i+1] == 'C'){
            ans += cnta;
            i++;
        }else cnta = 0;
    }
    cout << ans << endl;
    return 0;
}