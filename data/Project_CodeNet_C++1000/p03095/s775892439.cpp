#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> vec(26, 0);
    rep(i,N){
        ll x = S[i] - 'a';
        vec[x]++;
    }
    ll ans = 1;
    rep(i,26){
        ans = (ans * (vec[i] + 1)) % 1000000007;
    }
    cout << (ans + 1000000007 - 1) % 1000000007 << endl;
}