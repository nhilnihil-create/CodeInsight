#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, k;
    int num[200020]={0};
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int l;
        cin >> l;
        num[l] += 1;
    }
    sort(num+1, num+n+1, greater<int>());
    int s = 0;
    for (int i=1; i<=k; i++) {
        s += num[i];
    }
    int ans = n - s;
    if (ans >= 0) cout << ans << endl;
    else cout << 0 << endl;
    return 0;
}