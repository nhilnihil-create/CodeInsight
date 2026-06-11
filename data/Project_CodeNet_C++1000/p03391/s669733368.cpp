#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    b.resize(n);
    bool ok = 1;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] >> b[i];
        ok &= a[i] == b[i];
    }
    if(ok) finish(0);
    ll sum = 0;
    for(auto &i : a) sum += i;
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(b[i] < a[i]){
            ans = max(ans, sum - b[i]);
        }
    }
    cout << ans << endl;
}
