#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int a, b;
    int ans = 0;
    cin >> a >> b;
    if(a == 1){
        if(b >= a) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else{
        if(b >= a) cout << a << endl;
        else cout << a - 1 << endl;
    }

    return 0;
}