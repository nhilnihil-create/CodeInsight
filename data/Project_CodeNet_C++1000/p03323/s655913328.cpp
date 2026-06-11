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

    bool ok = true;
    if((a > 8) || (b > 8)) ok = false;

    if(ok) cout << "Yay!" << endl;
    else cout << ":(" << endl;
     
    return 0;
}