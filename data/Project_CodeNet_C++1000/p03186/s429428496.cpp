#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << b+min(c, a+b+1) << '\n';
    return 0;
}
