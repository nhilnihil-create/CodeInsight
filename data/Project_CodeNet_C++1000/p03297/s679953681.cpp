#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, n) for(int i = n-1; i >= 0; i--)
#define rep4(i, x, n) for(int i = x; i > n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

ll gcd(ll x, ll y){
    ll a = max(x, y);
    ll b = min(x, y);
    while(b > 0){
        ll s = a%b;
        ll t = b;
        a = t;
        b = s;
    }
    return a;
}

int main(){
    int T;
    cin >> T;
    ll A, B, C, D;
    string S[T];
    string yes = "Yes";
    string no = "No";
    rep(i, T){
        cin >> A >> B >> C >> D;
        if(A < B) S[i] = no;
        elif(B > D) S[i] = no;
        elif(C >= B-1) S[i] = yes;
        elif(A % B > C) S[i] = no;
        else{
            ll a = A % B;
            ll g = gcd(B, D);
            ll m = a + ((C-a)/g + 1)*g;
            if(0 <= m-B) S[i] = yes;
            else S[i] = no;
        }
    }
    rep(i, T) cout << S[i] << endl;
}