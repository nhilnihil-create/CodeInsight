#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    vector<int> a(3);
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    cout << abs(a[0] - a[1]) + abs(a[1] - a[2]) << endl;
    

    return 0;
}