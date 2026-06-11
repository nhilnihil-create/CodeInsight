#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x)
#define printl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
 
int main(){
    ll N; cin >> N;
    vll p(N+1);
    rep(i, 0, N){
        ll a; cin >> a;
        p[a] = i+1;
    }
    ll c = 1;
    ll mx = 1;
    rep(i, 2, N+1){
        if(p[i] > p[i-1]){
            c++;
            if(i == N){
                mx = max(mx, c);
            }
        }else{
            mx = max(mx, c);
            c = 1;
        }
    }
    cout << N - mx;
}