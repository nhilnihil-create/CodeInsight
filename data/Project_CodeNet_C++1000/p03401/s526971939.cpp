#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define ALL(x) (x).begin(),(x).end()

using ll = long long;
using ull = unsigned long long;
 
const ll INF = 1LL<<60;
const int MINF = 1e9;
const int MOD = 1e9+7;

using vi = vector<int>;
using vii = vector<vi>;

template<typename T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
T GCD(T a,T b){ return b ? GCD(b,a%b) : a ;}
template<typename T>
T LCM(T a,T b){ return a*b / GCD(a,b) ;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;cin >> n;
    vi a(n+2,0);rep(i,n)cin >> a[i+1];
    a.push_back(0);

    int sum = 0;
    for(int i=1;i<n+2;i++){
        sum += abs(a[i] - a[i-1]);
    }

    for(int i=1;i<n+1;i++){
        ll ans = sum - abs(a[i] - a[i-1]) - abs(a[i] - a[i+1]) + abs(a[i+1] - a[i-1]);
        cout << ans << endl;
    }
    return 0;
}