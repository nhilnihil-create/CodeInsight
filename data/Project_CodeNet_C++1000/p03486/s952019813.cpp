#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(0);
    string s, t; cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());

    cout << (s<t? "Yes": "No") << endl;
}
