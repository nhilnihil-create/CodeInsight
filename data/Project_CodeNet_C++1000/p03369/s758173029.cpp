#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

string s;
int cnt;
int main() {
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == 'o')
            ++cnt;
        
    cout << cnt * 100 + 700 << endl;    
    return 0;
}
