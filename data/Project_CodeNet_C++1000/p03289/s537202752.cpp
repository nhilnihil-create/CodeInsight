#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

bool noC(string in) {
    int count = 0, n = in.size();
    for (int i = 2; i < n - 1; ++i) {
        if (in[i] == 'C')count++;
    }
    return (count == 1);
}

bool noUp(string in) {
    int n = in.size();
    for (int i = 1; i < n; ++i) {
        if (isupper(in[i]) && in[i] != 'C') return false;
    }
    return true;
}

int main() {
    fastio;
    string in;
    cin >> in;

    if (in[0] != 'A') cout << "WA";
    else if (!noC(in)) cout << "WA";
    else if (!noUp(in)) cout << "WA";
    else cout << "AC";

    return 0;
}