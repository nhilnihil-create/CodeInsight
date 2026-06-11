#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int r;
    cin >> r;
    
    if(r < 1200) cout << "ABC" << endl;
    else if(r < 2800) cout << "ARC" << endl;
    else cout << "AGC" << endl;
    
    return 0;
}