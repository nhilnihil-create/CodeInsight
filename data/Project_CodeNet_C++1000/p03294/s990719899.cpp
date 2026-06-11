#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;


int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n;  i++){
        cin >> a[i];
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += (a[i] - 1);
    }
    cout << ans << endl;
    return 0;
}