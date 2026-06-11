#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<P> a(n);
    rep(i, n){
        int A, B;
        cin >> A >> B;
        a[i].first = A; a[i].second = B;
    }

    sort(a.begin(), a.end());

    int f = 0;
    ll ans = 0;
    rep(i, m){
        if(a[f].second == 0) f++;
        ans += (ll)a[f].first;
        a[f].second--;
    }

    cout << ans << endl;

    return 0;
}   

/*

2 3
1 2 3, 2 3 4

all:3*3=9
odd:2*1=2
9-2
*/