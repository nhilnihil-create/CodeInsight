#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

// keyenence keyenccce
void solve() {
    string s; cin >> s;
    bool f = false;
    if(s.substr(s.size()-7, 7) == "keyence") 
    f = true;
    if(s.substr(0, 1) == "k" && s.substr(s.size()-6, 6) == "eyence")
    f = true;
    if(s.substr(0, 2) == "ke" && s.substr(s.size()-5, 5) == "yence")
    f = true;
    if(s.substr(0, 3) == "key" && s.substr(s.size()-4, 4) == "ence")
    f = true;
    if(s.substr(0, 4) == "keye" && s.substr(s.size()-3, 3) == "nce")
    f = true;
    if(s.substr(0, 5) == "keyen" && s.substr(s.size()-2, 2) == "ce")
    f = true;
    if(s.substr(0, 6) == "keyenc" && s.substr(s.size()-1, 1) == "e")
    f = true;
    if(s.substr(0, 7) == "keyence")
    f = true;
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
