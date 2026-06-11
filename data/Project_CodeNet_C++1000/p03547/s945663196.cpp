#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    char X, Y;
    cin >> X >> Y;
    if (X - Y > 0) cout << ">" << endl;
    else if (X - Y == 0) cout << "=" << endl;
    else cout << "<" << endl;
}
