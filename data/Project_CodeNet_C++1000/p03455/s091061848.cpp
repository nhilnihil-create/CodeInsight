#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a,b;
    cin >> a >> b;
    if (a * b % 2 == 0) cout << "Even" << endl;
    else cout << "Odd" << endl;
    return 0;
}