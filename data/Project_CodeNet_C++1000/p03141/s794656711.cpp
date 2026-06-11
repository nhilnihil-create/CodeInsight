#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}

int main(){
    int n;
    cin >> n;
    int a, b;
    ll sum_a = 0;
    vi c(n);
    rep(i, n){
        cin >> a >> b;
        c[i] = a+b;
        sum_a += a;
    }
    Sort(c);
    rep(i, n){
        if(i%2 == 1){
            sum_a -= c[n-i-1];
        }
    }
    cout << sum_a << endl;
    return 0;
}