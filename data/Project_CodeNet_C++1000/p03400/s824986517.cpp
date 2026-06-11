#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, d, x, cnt; 
    cin >> n >> d >> x;
    int ans = x;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++){
        cnt = 0;
        while (true){
            if (cnt*a[i]+1 <= d) cnt++;
            else break;
        }
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}