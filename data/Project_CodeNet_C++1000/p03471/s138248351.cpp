#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, y;
    cin >> n >> y;
    // bool can = false;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n - i; ++j){
            if(y == 10000 * i + 5000 * j + 1000 * (n - i - j)){
                    cout << i << " " <<  j << " " << n - i - j << endl;
                    return 0;
            }
        }
    }
    cout << -1 <<" " << -1 << " " << -1 << endl;
    return 0;
}