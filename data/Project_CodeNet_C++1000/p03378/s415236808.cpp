#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    for(int i=0; i<m; ++i){
       cin >> a[i];
    }

    auto it = lower_bound(a.begin(), a.end(), x);
    int t = distance(a.begin(), it);

    int tb = t;
    int tf = m-t;

    cout << min(tb, tf);
    return 0;
}