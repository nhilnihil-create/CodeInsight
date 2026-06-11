#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    ll l = 2, r = 2;
    for(int i = n - 1 ; i >= 0 ; i--){
        ll d = l / a[i] * a[i];
        if(d < l) d += a[i];
        l = d;
        r = r / a[i] * a[i];
        r += a[i] - 1;
        if(r < l) finish(-1);
    }
    cout << l << " " << r << endl;
}
