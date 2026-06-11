#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int all = 1, odd = 1;
    rep(i,n)  {
        cin >> a[i];
        if(a[i]%2==0) odd*=2;
        all*=3; 
    } 
    int ans = all-odd;
    cout << ans << endl;

    return 0;
}