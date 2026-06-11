#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;
typedef pair<int,int> P;

bool check(ll a){
    int s = 0; while(pow(10,s) <= a) s++;
    vector<bool> check(3,false);
    rep(i,s){
        int num = a % 10;
        if(num == 3) check[0] = true;
        if(num == 5) check[1] = true;
        if(num == 7) check[2] = true;
        a /= 10;
    }
    if(check[0] == true && check[1] == true && check[2] == true) return true;
    return false;
}

ll dfs(ll a, ll n){
    ll ans = 0;
    if(a > n) return ans;
    if (check(a)) ans++;
    ans += dfs(10*a + 3, n);
    ans += dfs(10*a + 5, n);
    ans += dfs(10*a + 7, n);
    return ans;
}

int main(){
    ll n; cin >> n;
    cout << dfs(0, n) << endl;
}