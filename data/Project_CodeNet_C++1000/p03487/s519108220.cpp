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
    map<int,int> mp;
    rep(i,n){
        int a;cin >> a;
        if(mp[a] == 0)mp[a] = 1;
        else mp[a]++;
    }
    ll ans = 0;
    for(auto i : mp){
        if(i.first - i.second > 0)ans += i.second;
        else if(i.first - i.second < 0)ans += i.second - i.first;
    }
    cout << ans << endl;
    return 0;
}