#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007
ll n , ans;

void dfs(ll x){
    if(x > n){
        return;
    }
    string s = to_string(x);
    bool f3 = 0 , f5 = 0, f7 = 0;
    for(auto e : s){
        if(e == '3'){
            f3 = 1;
        }else if(e == '5'){
            f5 = 1;
        }else if(e == '7'){
            f7 = 1;
        }
    }
    if(f3 && f5 && f7){
        ans++;
    }
    dfs(x*10 + 3);
    dfs(x*10 + 5);
    dfs(x*10 + 7);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    dfs(3);
    dfs(5);
    dfs(7);
    cout<<ans;

}