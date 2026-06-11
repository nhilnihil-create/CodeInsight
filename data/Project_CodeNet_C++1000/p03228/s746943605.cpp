#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a,b,k;
    cin >> a >> b >> k;
    rep(i,k/2){
        if(a%2==1)a--;
        b += a/2;
        a/=2;
        if(b%2==1)b--;
        a += b/2;
        b/= 2;
    }
    if(k%2){
        if(a%2==1)a--;
        b += a/2;
        a/=2;
    }
    cout << a << " " << b << endl;
}