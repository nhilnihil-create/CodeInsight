#include <bits/stdc++.h>
#include <numeric>
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;

string S;

bool solve() {
    if (S.find("AA") != string::npos) return false;
    if (S.find("KIH") == string::npos) return false;

    size_t c;
    while((c = S.find('A')) != string::npos) {
        S.erase(c, 1);
    }

    return S == "KIHBR";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> S;

    cout << (solve() ? "YES" : "NO") << "\n"; 
}