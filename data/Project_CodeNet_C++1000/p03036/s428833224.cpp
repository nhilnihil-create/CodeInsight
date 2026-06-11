#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int r, d, x;
    cin >> r >> d >> x;
    
    rep(i,10) {
        x = r * x - d;
        cout << x << endl;
    }
    
    
    return 0;
}
