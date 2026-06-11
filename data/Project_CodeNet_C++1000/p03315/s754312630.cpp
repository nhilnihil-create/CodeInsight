#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    vector<char> S(4);
    rep(i, 0, 4) cin >> S.at(i);
    int x = 0;
    rep(i, 0, 4){
        if (S.at(i) == '+') x++;
        else x--;
    }
    cout << x << endl;
}
