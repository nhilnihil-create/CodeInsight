#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;


int main() {

    int n,m; cin >> n >> m;
    cout << (((n-m)*100 + m*1900)*pow(2,m));
    return 0;
}
