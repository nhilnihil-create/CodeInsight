#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if(a + b == 15) {
        cout << "+" << '\n';
    }
    else if(a * b == 15) {
        cout << "*" << '\n';
    }
    else {
        cout << "x" << '\n';
    }

    return 0;
}
