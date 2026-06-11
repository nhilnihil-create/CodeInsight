#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    string s; cin >> s;
    int ans = 700;
    rep(i, 3) if(s[i] == 'o') ans+= 100;
    cout << ans << endl;
}