#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    bool c1 = A==B;
    bool c2 = B==C;
    bool c3 = C==A;
    if(c1) cout << C << endl;
    else if(c2) cout << A << endl;
    else if(c3) cout << B << endl;
}