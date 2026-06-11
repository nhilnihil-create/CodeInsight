#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int a, b, x;
    cin >> a >> b >> x;

    if(x - a < 0) cout << "NO" << endl;
    else{
        if(x - a <= b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}