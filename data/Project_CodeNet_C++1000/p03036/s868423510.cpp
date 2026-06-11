#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int r, d;
    cin >> r >> d;
    int x;
    cin >> x;
    for(int i = 0; i < 10; i++){
        int x_next;
        x_next = r * x - d; 
        cout << x_next << endl;
        x = x_next;
    }
    return 0;
}