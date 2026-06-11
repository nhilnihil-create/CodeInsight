#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if(s[n-1] == '1'){
        cout << -1 << endl;
        return 0;
    }
    rep(i, n/2){
        if(s[i] != s[n-2-i]){
            cout << -1 << endl;
            return 0;
        }
    }
    if(s[0] == '0'){
        cout << -1 << endl;
        return 0;
    }

    int v = 1;
    rep(i, n-1){
        cout << v << ' ' << i + 2 << endl;
        if(s[i] == '1')v = i + 2;
    }
    
}