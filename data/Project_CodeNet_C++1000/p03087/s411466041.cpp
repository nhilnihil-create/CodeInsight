#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}


int main() {
    int n,q; cin >> n >> q;
    string s; cin >> s; int ans = 0;vector<int> v(n,0);
    for(int i = 1;i < s.length();i++){
        if(s[i-1] == 'A' && s[i] == 'C'){
            v[i] = v[i-1] + 1;
        }else{
            v[i] = v[i-1];
        }
    }
    for(int i = 0;i < q;i++){
        int d,f; cin >> d >> f;
        cout << v[f-1]-v[d-1] << endl;
    }
}
