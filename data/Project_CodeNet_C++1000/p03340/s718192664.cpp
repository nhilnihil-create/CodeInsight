#include <cstdio>
#include <iostream>
#define N 200020
using namespace std;
typedef long long ll;
int main(){
    ll n, s, a[N], ans = 0, j = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll sa = 0, sb = 0;
    for(int i = 1; i <= n; i++){
        while(j + 1 <= n && sb + a[j + 1] == (sa ^ a[j + 1])){
            sa ^= a[j + 1];
            sb += a[j + 1];
            j++;
        }
        ans = ans + j - i + 1;
        sa ^= a[i];
        sb -= a[i];
    }
    cout << ans << endl;
    return 0;
}