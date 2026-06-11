#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main(){
    int N;
    cin >> N;
    map<char, i64> m;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        m[s[0]]++;
    }
    i64 ans = 0;
    ans += m['M'] * m['A'] * m['R'];
    ans += m['M'] * m['A'] * m['C'];
    ans += m['M'] * m['A'] * m['H'];
    ans += m['C'] * m['A'] * m['R'];
    ans += m['H'] * m['A'] * m['R'];
    ans += m['M'] * m['C'] * m['R'];
    ans += m['M'] * m['H'] * m['R'];
    ans += m['C'] * m['A'] * m['H'];
    ans += m['H'] * m['C'] * m['R'];
    ans += m['M'] * m['C'] * m['H'];
    cout << ans << endl;
    return 0;
}
