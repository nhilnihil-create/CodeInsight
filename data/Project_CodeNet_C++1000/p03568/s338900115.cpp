#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> odds(n,0);
    for(int i = 0; i < n; i++){
        if((a[i] - 1) % 2 == 1)
        odds[i]++;
        if(a[i] % 2 == 1)
        odds[i]++;
        if((a[i] + 1) % 2 == 1)
        odds[i]++;
    }
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans *= 3;
    }
    ll k = 1;
    for(ll i = 0; i < n; i++){
        k *= odds[i];
    }
    cout << ans - k << endl;
}