#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> alp(26);
    rep(i,n){
        char c = s.at(i);
        if (c == 'a') alp[0]++;
        else if (c == 'b') alp[1]++;
        else if (c == 'c') alp[2]++;
        else if (c == 'd') alp[3]++;
        else if (c == 'e') alp[4]++;
        else if (c == 'f') alp[5]++;
        else if (c == 'g') alp[6]++;
        else if (c == 'h') alp[7]++;
        else if (c == 'i') alp[8]++;
        else if (c == 'j') alp[9]++;
        else if (c == 'k') alp[10]++;
        else if (c == 'l') alp[11]++;
        else if (c == 'm') alp[12]++;
        else if (c == 'n') alp[13]++;
        else if (c == 'o') alp[14]++;
        else if (c == 'p') alp[15]++;
        else if (c == 'q') alp[16]++;
        else if (c == 'r') alp[17]++;
        else if (c == 's') alp[18]++;
        else if (c == 't') alp[19]++;
        else if (c == 'u') alp[20]++;
        else if (c == 'v') alp[21]++;
        else if (c == 'w') alp[22]++;
        else if (c == 'x') alp[23]++;
        else if (c == 'y') alp[24]++;
        else if (c == 'z') alp[25]++;
    }
    ll ans = 1;
    rep(i,26){
        ans *= (alp[i] + 1);
        ans %= MOD;
    }
    ans--;
    ans %= MOD;
    cout << ans << endl;
}