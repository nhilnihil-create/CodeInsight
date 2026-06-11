#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define sort_be(a) sort(a.begin(), a.end());
#define reverse_be(a) reverse(a.begin(), a.end());
#define vi vector<int>
#define vvii(a, b, c) vector<vector<int>> a(b, vector<int>(c));
using namespace std;
using ll = long long;
int main(){
    ll k, a, b;
    cin >> k >> a >> b;
    cout << max(k + 1 , ((k - a + 1) / 2) * (b - a) + a + (k - a + 1) % 2) << endl;
}