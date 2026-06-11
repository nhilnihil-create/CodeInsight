#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    rep(i,n) {
        cin >> a[i];
        if(a[i]%2 == 0) cnt++;
    }
    int ans = pow(3,n);
    ans -= pow(2,cnt);
    cout << ans << endl;
}