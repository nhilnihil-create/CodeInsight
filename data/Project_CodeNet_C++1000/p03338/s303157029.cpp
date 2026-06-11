#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n; string s; cin >> n >> s;
    int ans = 0;
    for(int i = 1;i < n;i++){
        string x = s.substr(0,i);sort(x.begin(),x.end());
        string y = s.substr(i,s.length());sort(y.begin(),y.end());
        x.erase(unique(x.begin(),x.end()),x.end());
        y.erase(unique(y.begin(),y.end()),y.end());
        int cnt = 0;
        for(int j = 0;j < x.length();j++){
            if(y.find(x[j]) != string::npos){
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans;
}
