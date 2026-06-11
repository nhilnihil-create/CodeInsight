#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> P;
const int INF = 1e15;

signed main(){
    int n, sum = 0;
    cin >> n;
    vector<int> a(n), b(n);
    int MIN = INF;
    bool f = true;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        if(a[i] != b[i]) f = false;
        sum += a[i];
        if(a[i] > b[i]) MIN = min(MIN, b[i]);
    }
    if(f) cout << 0 << endl;
    else cout << sum - MIN << endl;
}