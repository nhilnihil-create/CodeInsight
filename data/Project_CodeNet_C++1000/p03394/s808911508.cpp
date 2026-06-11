#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N;
    cin >> N;
    if(N == 3){
        cout << 2 << ' ' << 3 << ' ' << 25 << endl;
        exit(0);
    }
    int n = min(15000, N-N%2), a = N-n;
    int b = n/3, c = n%3;
    rep(i, b) cout << 6*i+2 << ' ' << 6*i+3 << ' ' << 6*i+4 << endl;
    if(c == 1) cout << 6*b+3 << endl;
    elif(c == 2) cout << 6*b+2 << ' ' << 6*b+4 << endl;
    rep2(i, 1, a+1) cout << 6*i << endl;
}