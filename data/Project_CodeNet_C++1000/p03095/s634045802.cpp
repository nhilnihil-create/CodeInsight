#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll mod = 1000000007;

    vector <int> table(26,1);

    rep(i,n){
        char tmp = s[i];
        int tmp1 = tmp - 97;
        table[tmp1] ++;
    }

    long long ans = 1;
    rep(i,26){
        ans *= table[i];
        ans %= mod;
    }
    ans --;

    cout << ans << endl;

}