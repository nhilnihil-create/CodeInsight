#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b;
    cin >> a >> b;
    bool flg = false;
    for(int c = 1; c <= 3; c++){
        if(a * b * c % 2 == 1) flg = true;
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}