#include<bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define Dcout(a) cout << setprecision(20) << a << endl
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using ll = long long;
using PAIR = pair<int, int>;
using Graph = vector<vector<int>>;
const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/

/******** User-defined Function *******/
map<long long, long long> prime_factorize(long long n) {
    map<long long, long long> res;
    for (long long p = 2; p * p <= n; ++p) {
        while (n % p == 0) { ++res[p]; n /= p; }
    }
    if (n != 1) res[n] = 1;
    return res;
}
/**************************************/

/********** Main()  function **********/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    char c[4] = { 'A', 'T', 'G', 'C'};

    int seq = 0;
    int ans = -1;
    rep(i,s.size()){
        bool flag = false;
        rep(j,4){
            if(s[i]==c[j]){
                seq++;
                flag = true;
                break;
            }
        }

        if(flag==false){
            chmax(ans, seq);
            seq = 0;
        }else if(i==s.size()-1){
            chmax(ans, seq);
        }
    }

    cout << ans << endl;
}
/********  Main() Ends Here *************/
