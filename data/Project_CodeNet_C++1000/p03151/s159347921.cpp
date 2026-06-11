#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    int n;
    cin >> n;
    ll a[n], b[n];
    ll asum = 0, bsum = 0;
    rep(i, n){
        cin >> a[i];
        asum+= a[i];
    }
    rep(i, n){
        cin >> b[i];
        bsum += b[i];
    }

    if (asum < bsum){
        cout << -1 << endl;
        return 0;
    }

    ll diff = asum - bsum;

    vector<ll> d;
    rep(i, n){
        if (a[i] >= b[i]) d.push_back(a[i] - b[i]);
    }
    sort(d.begin(), d.end());

    int i = 0;
    while (diff - d[i] >= 0 && i < d.size()){
        diff -= d[i];
        i ++;
    }

    cout << n - i << endl;

    return 0;
}