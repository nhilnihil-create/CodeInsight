#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[200005], b[200005];
int ca[200005], cb[200005];
int n;
int ans = 0;

void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    init();
    vector<int> Z, O;
    Z.reserve(n); O.reserve(n);
    for(int j = 0; j <= 28; j++){
        Z.clear(); O.clear();
        for(int i = 1; i <= n; i++){
            if(a[i] >> j & 1) O.push_back(a[i]);
            else Z.push_back(a[i]);
        }
        copy(Z.begin(), Z.end(), a + 1);
        copy(O.begin(), O.end(), a + Z.size() + 1);
        copy(a + 1, a + n + 1, ca + 1);
        for(int i = 1; i <= n; i++) ca[i] &= (1 << j + 1) - 1;
        Z.clear(); O.clear();
        for(int i = 1; i <= n; i++){
            if(b[i] >> j & 1) O.push_back(b[i]);
            else Z.push_back(b[i]);
        }
        copy(Z.begin(), Z.end(), b + 1);
        copy(O.begin(), O.end(), b + Z.size() + 1);
        copy(b + 1, b + n + 1, cb + 1);
        for(int i = 1; i <= n; i++) cb[i] &= (1 << j + 1) - 1;
        int p1 = n, p2 = n, p3 = n;
        int bit = 0;
        for(int i = 1; i <= n; i++){
            while(p1 && ca[i] + cb[p1] >= 1 << j) --p1;
            while(p2 && ca[i] + cb[p2] >= 2 << j) --p2;
            while(p3 && ca[i] + cb[p3] >= 3 << j) --p3;
            bit ^= (p2 - p1) + (n - p3);
        }
        if(bit & 1) ans |= 1 << j;
    }
    cout << ans << '\n';
}