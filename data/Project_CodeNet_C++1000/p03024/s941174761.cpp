#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    ll cnt = 0;
    for (char c : S) {
        if (c == 'x') cnt++;
    }

    if (cnt < 8) cout << "YES\n";
    else cout << "NO\n";
}