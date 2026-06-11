#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    vector<int> x(1001);
    x.at(0) = 0;
    rep(i, 1, 1000){
        x.at(i) = x.at(i - 1) + i;
    }
    int y = b - a;
    cout << x.at(y - 1) - a << endl;
    
}