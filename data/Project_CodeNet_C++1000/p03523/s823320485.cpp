
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, d, n) for (int i = (d); i < (n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main(){

    string s;
    cin >> s;

    string akiba = "KIHBR";
    s = " " + s + " ";
    bool ok = true;
    int idx = 0;

    set<char> f;
    REP(i, 1, s.length() - 1){
        if (s[i] != 'A'){
            if (f.find(s[i]) != f.end()){
                ok = false;
            }
            f.insert(s[i]);
        }
        if (s[i - 1] == s[i]){
            ok = false;
            break;
        }
        else if (s[i - 1] == 'K' && s[i + 1] == 'I'){
            ok = false;
            break;
        }
        else if (s[i - 1] == 'I' && s[i + 1] == 'H'){
            ok = false;
            break;
        }
        if (s[i] == akiba[idx]){
            idx++;
        }
    }
    if (ok && idx == 5 && f.size() == 5){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
