#include<iostream>
#include<string>
#include<vector>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    ll n, y;
    cin >> n >> y;
    rep(i, n+1){
        rep(j, n+1){
            if(i + j > n) break;
            int k = n - i - j;
            if(10000*i + 5000*j + 1000*k == y){
                printf("%d %d %d\n", i, j, k);
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;
}