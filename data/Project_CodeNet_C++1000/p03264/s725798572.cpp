#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int k;
    cin >> k;
    int odd, even;
    
    if(k%2 == 0){
        odd = k / 2;
        even = k / 2;
    }
    else{
        even = k / 2;
        odd = even + 1;
    }
    cout << odd * even << endl;

    return 0;
}