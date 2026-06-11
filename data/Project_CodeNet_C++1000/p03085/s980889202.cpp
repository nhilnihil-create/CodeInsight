#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(void) {
    char c;
    cin >> c;

    char ans;

    switch(c) {
        case 'A':
        ans = 'T';
        break;
        case 'C':
        ans = 'G';
        break;
        case 'G':
        ans = 'C';
        break;
        case 'T':
        ans = 'A';
        break;
    }
    cout << ans << endl;
    return 0;
}
