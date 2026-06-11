#include "bits/stdc++.h"
#include <math.h>
using namespace std;
void solve(){
    int n, h, w;
    cin >> n, cin >> h, cin >> w;
    cout << (n - h + 1) * (n - w + 1) << endl;
}
int main(){
    solve();
    return 0;
}