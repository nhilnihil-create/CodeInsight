#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (s[k - 1] == 'A') s[k - 1] = 'a';
    else if (s[k - 1] == 'B') s[k - 1] = 'b';
    else s[k - 1] = 'c';

    cout << s; 
    
}