#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
const double PI=acos(-1);

void solve(){
    ll n, m; cin >> n >> m;
    cout << pow(2, m)*(1900*m + 100*(n - m)) << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}