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

    ll A, B, C;
    cin >> A >> B >> C;

    if (A == B && B == C) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}