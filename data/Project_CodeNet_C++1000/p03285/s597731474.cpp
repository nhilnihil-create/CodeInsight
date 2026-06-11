#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    
    bool flg = false;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 16; j++){
            if(4 * i + 7 * j == n) flg = true;
        }
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}