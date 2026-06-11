#include<bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> a(100);

int main(){
    int n; cin >> n;
    int cnt=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]%2==0) cnt++;
    }
    ll ans = pow(3, n);
    ll odd = pow(2, cnt);
    ans = ans - odd;

    cout << ans << endl;
    return 0;

}