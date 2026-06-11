#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
typedef pair<int, int> ii;

const int mod = 1e9 + 7;

int n, m;
string a, b;

map<int, char> mymap;

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    cin >> a >> b;
    int gcd = __gcd(n, m);
    int lcm = (n * m) / gcd;
    for(int i = 0; i <= (n - 1); i++)
        mymap[i * lcm / n + 1] = a[i];
    for(int i = 0; i <= (m - 1); i++) {
        if(mymap.count(i * lcm / m + 1)) {
            if(mymap[i * lcm / m + 1] == b[i])
                continue;
            else {
                cout << "-1\n";
            exit(0);
            }
        }
        else {
            mymap[i * lcm / m + 1] = b[i];
        }
    }
    cout << lcm;
}
