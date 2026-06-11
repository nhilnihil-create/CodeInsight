#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    ll a, b, k;
    cin >> a >> b >> k;

    rep(i, k){
        if (i % 2 == 0){
            if (a % 2 != 0) a--;
            b += a / 2;
            a /= 2;
        }
        else if (i % 2 != 0){
            if (b % 2 != 0) b--;
            a += b / 2;
            b /= 2;
        }
    }
    cout << a << " " << b << endl;

    return 0;
}