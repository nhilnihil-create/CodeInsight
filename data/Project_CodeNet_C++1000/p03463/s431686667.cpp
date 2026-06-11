#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if((b-a)%2 == 0) cout << "Alice" << endl;
    else cout << "Borys" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
