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
    int a, b; cin >> a >> b;
    if(a+b == 15) cout << '+' << endl;
    else if(a*b == 15) cout << '*' << endl;
    else cout << 'x' << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
