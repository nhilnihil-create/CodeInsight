#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

int n;

string s;

void bye() {
    cout << "-1\n";
    exit(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> s;
    n = s.length();
    s = "+" + s;
    if(s[1] == '0')
        bye();
    if(s[n] == '1')
        bye();
    for(int i = 1; i <= n - 1; i++) {
        if(s[i] != s[n - i])
            bye();
    }
    cout << "1 2\n";
    int pter = 3, lmao = 2;
    for(int i = 2; i <= n - 1; i++) {
        if(s[i] == '1') {
            cout << lmao << " " << pter << "\n";
            lmao = pter;
            pter++;
        }
        else {
            cout << lmao << " " << pter << "\n";
            pter++;
        }
    }
}
