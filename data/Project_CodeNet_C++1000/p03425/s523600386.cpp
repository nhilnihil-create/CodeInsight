#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main(){
    int n; cin >> n;
    string march = "MARCH";
    map<char, ll> ma;
    rep(i,n){
        string s; cin >> s;
        ma[s[0]]++;
    }
    ll ans = 0;
    int cnt = 0;
    for(int i = 0; i < 5; ++i){
        for(int j = i+1; j < 5; ++j){
            for(int k = j+1; k<5; ++k){
                ans += ma[march[i]]*ma[march[j]]*ma[march[k]];
            }
        }
    }
    cout << ans << endl;
}