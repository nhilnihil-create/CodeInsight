#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int n,maxim=0,s;
    ll sum=0, maxsum=0;
    ll up;
    cin >> n;
    vector<int>a(n);
    rep(i, n) {
        cin >> s;
        sum += s - 1;
    }
   
    cout << sum << endl;


    return 0;
}