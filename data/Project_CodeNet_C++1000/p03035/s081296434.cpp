#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main(){
    int A, B;
    cin >> A >> B;
    if (A >= 13) cout << B << endl;
    else if (A >= 6) cout << B/2 << endl;
    else cout << 0 << endl;
}