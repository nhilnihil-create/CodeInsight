#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
#define ll int64_t
#define REP(i, n) for (ll i=0; i<n; i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<ll> N(4);
    REP(i, 4) cin >> N[i];

    sort(N.begin(), N.end());

    if (N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9) cout << "YES" << endl;
    else cout << "NO" << endl;
}