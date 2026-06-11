#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x[10] = {};
    x[a]++; x[b]++; x[c]++; x[d]++;

    if(x[1] == 1 && x[4] == 1 && x[7] == 1 && x[9] == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    return 0;
}