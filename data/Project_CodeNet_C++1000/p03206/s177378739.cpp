#include <bits/stdc++.h>
#define nl ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()

using namespace std;

int main() {
    nl // 163 braces

    int d; cin >> d;
    if(d == 25) cout << "Christmas";
    else if(d == 24) cout << "Christmas Eve";
    else if(d == 23) cout << "Christmas Eve Eve";
    else cout << "Christmas Eve Eve Eve";

    return 0;
}