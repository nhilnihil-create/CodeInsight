#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    string s;
    cin >> s;

    ll size = s.size();
    ll ans = 0;
    int count = 0;

    rep(i, size){
        if(s[i] == 'W'){
            ans += (i - count);
            count++;
        }
    }

    cout << ans << endl;
    return 0;
}
