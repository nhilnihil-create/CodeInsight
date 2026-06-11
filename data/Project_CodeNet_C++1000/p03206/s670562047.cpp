#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int d;
    cin >> d;

    if(d == 25) cout << "Christmas" << endl;
    else if(d == 24) cout << "Christmas Eve" << endl;
    else if(d == 23) cout << "Christmas Eve Eve" << endl;
    else if(d == 22) cout << "Christmas Eve Eve Eve" << endl;
    
    return 0;
}