#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    int a[3];
    rep(i, 3) cin >> a[i];
    sort(a, a + 3);

    int ans = 0;

    int i, j, k;
    if(abs(a[0] - a[1]) % 2 == 0)
        i = 0, j = 1, k = 2;
    else if(abs(a[0] - a[2]) % 2 == 0)
        i = 0, j = 2, k = 1;
    else if(abs(a[1] - a[2]) % 2 == 0)
        i = 1, j = 2, k = 0;

    ans += abs(a[i] - a[j]) / 2;
    int m = max(a[i], a[j]);
    a[i] = m, a[j] = m;
    int p = a[i], q = a[k];

    if(p > q){
        if((p - q) % 2 == 0){
            ans += (p - q) / 2;
        }else{
            ans += (p + 1 - q) / 2 + 1;
        }
    }else{
        ans += q - p;
    }
    cout << ans << endl;
    return 0;
}