#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    //解は[l,r)に存在する
    int l = -1, r, N;
    //各席の状況
    map<int, int> mp;
    cin >> N;
    while(true){
        int n;
        if(l == -1) n = 0;
        else n = (l+r)/2;
        cout << n << endl;
        string s;
        cin >> s;
        if(s == "Vacant") break;
        elif(s == "Male") mp[n] = 0;
        else mp[n] = 1;
        if(l == -1) l = 0, r = N;
        else{
            if(((n-l)&1)^mp[l]^mp[n]) r = n;
            else l = n;
        }
    }
}