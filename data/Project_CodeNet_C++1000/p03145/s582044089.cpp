#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vi l(3);

    for ( int i = 0; i < 3; i++ ) cin >> l[i];

    sort(l.begin(), l.end());

	cout << l[0] * l[1] / 2 << endl;

    return 0;
}
