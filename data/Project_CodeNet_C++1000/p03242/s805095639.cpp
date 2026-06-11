#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    string n;
    cin >> n;
    for(int i = 0; i < 3; i++){
        if(n[i] == '9') n[i] = '1';
        else if(n[i] == '1') n[i] = '9';
    }
    cout << n << endl;
    return 0;
}