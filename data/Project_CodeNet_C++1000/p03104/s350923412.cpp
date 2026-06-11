
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int f(ll a, ll b, ll div){
    ll qa = a / div;
    ll qb = b / div;
    ll ra = a % div;
    ll rb = b % div;
    if (qa % 2 == 0 && qb % 2 == 0) return 0;
    else if (qa % 2 != 0 && qb % 2 != 0){
        if ((ra + rb) % 2 == 0) return 1;
        else return 0;
    }
    else if (qa % 2 != 0){
        if (ra % 2 != 0) return 1;
        else return 0;
    }
    else if (qb % 2 != 0){
        if (rb % 2 == 0) return 1;
        else return 0;
    }
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll div = 1;
    while(div <= b) div *= 2;
    div /= 2;
    ll ans = 0;
    while(div > 1){
        ans *= 2;
        ans += f(a, b, div);
        div /= 2;
    }
    ans *= 2;
    ll n = b-a+1;
    if (b % 2 != 0 && a % 2 != 0){
        if ((n / 2 + 1) % 2 != 0) ans++;
    } 
    else{
        if ((n/2) % 2 != 0) ans++;
    } 
    cout << ans << endl;
    return 0;
}