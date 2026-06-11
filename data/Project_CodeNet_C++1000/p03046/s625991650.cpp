#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int m, k;
    cin >> m >> k;
    if(k >= (1 << m))cout << -1 << endl;
    else if(k == 1 && m == 1)cout << -1 << endl;
    else if(k > 0){
        rep(i, (1 << m))if(i != k)cout << i << ' ';
        cout << k << ' ';
        rep(i, (1 << m))if((1 << m) - 1 - i != k)cout << (1 << m) - 1 - i << ' ';
        cout << k << endl;
    }else{
        rep(i, (1 << m))cout << i << ' ';
        rep(i, (1 << m))cout << (1 << m) - 1 - i << ' ';
        cout << endl;
    }
    
}