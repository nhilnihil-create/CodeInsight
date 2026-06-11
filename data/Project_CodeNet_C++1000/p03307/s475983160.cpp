#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    ll n;
    cin >> n;

    ll ans = n;
    int i = 2;
    while((ans%n != 0) || (ans%2 != 0) ){
        ans *= i;
        i++;
    }
    cout << ans << endl;
    return 0;
}