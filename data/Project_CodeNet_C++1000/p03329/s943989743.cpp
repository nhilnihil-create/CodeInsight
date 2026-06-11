#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    int a[12] = {1, 6, 36, 216, 1296, 7776, 46656, 9, 81, 729, 6561, 59049};
    int n;
    cin >> n;
    vector<vector<ll>> num(13, vector<ll>(n + 1, INF)); 
    num[0][0] = 0;
    for(int i = 1; i <= 12; i++){
        int val = a[i - 1];
        for(int j = 0; j <= n; j++){
            if(j < val) num[i][j] = num[i - 1][j];
            else{
                num[i][j] = min(num[i - 1][j], num[i][j - val] + 1);
            }
        }
    }
    //for(int i = 0; i <= 12; i++){ cout << "\n"; for(int j = 0; j <= n; j++) cout << num[i][j] << " ";}
    cout << num[12][n];
}