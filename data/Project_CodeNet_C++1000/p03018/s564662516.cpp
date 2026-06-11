#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    string S;
    cin >> S;
    S += 'D';
    int N = sz(S);
    int j = 0; ll cnt = 0, sum = 0;
    ll ans = 0;
    for(int i = 0; i < N;){
        if(S[i] == 'A') i++, j++;
        elif(i+1 < N && S[i] == 'B' && S[i+1] == 'C'){
            sum += j, i += 2, j++, cnt++;
        }
        else{
            ans += sum - cnt*(cnt-1)/2;
            j = cnt = sum = 0;
            i++;
        }
    }
    cout << ans << endl;
}