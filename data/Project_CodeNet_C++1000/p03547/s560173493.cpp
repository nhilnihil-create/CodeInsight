#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    char x, y;
    cin >> x >> y;
    if(x < y) cout << '<' << endl;
    else if(x > y) cout << '>' << endl;
    else cout << "=" << endl;

    return 0;
}