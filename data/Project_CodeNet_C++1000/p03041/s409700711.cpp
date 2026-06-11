
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> s;
    s[k - 1] -= ('A' - 'a');
    cout << s << endl;

    return 0;
}

