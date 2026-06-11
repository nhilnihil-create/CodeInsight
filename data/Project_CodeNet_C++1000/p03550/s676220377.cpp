#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

const int sz = 2005;
int n, z, w, a[sz];

void solve(){
    cin >> n >> z >> w;
    for(int i = 0; i < n; ++i) cin >> a[i];

    if(n==1){
        cout << abs(a[0]-w) << '\n';
    }
    else{
        cout << max(abs(a[n-1]-w), abs(a[n-1]-a[n-2])) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}