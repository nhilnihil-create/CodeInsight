#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok(const vector<ll> &v){
    for(int i=0; i<v.size(); ++i){
        if(v[0]!=v[i]){return false;}
    }
    return true;
}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    ll mi = LONG_LONG_MAX;
    for(int i=0; i<n; ++i){
        cin >> a[i]; mi = min(mi, a[i]);
    }
    bool br = false;
    while(1){
        for(int i=0; i<n; ++i){
            a[i] %= mi;
            if(a[i]==0){a[i] += mi;}
        }
        for(int i=0; i<n; ++i){
            mi = min(mi, a[i]);
        }
        if(ok(a)){break;}
    }
    cout << mi << endl;
    return 0;
}