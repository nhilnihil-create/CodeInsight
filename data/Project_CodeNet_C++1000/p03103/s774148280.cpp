#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printVector(vector<int> v) {
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

void printArray(ll A[], int size) {
    for (int i = 0; i <= size - 1; i++) cout << A[i] << ' ';
}

void printMap(map<ll, ll> m) {
    for (auto x : m) {
        cout << x.first << ' ' << x.second << '\n';
    }
    cout << '\n';
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    map<ll, ll> mapa;
    for (int i = 1; i <= n; i++) {
        //cout << i << '\n';
        ll a, b;
        cin >> a >> b;
        mapa[a] += b;
    }
    ll needed = m;
    ll tot = 0;
    //printMap(mapa);
    for (auto x : mapa) {
        if (x.second < needed) {
            tot += x.first * x.second;
            needed -= x.second;
            //cout << needed << '\n';
        }
        else {
            tot += x.first * needed;
            needed = 0;
            break;
        }
    }
    //cout << needed << '\n';
    cout << tot << '\n';
    return 0;
}