#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int aa, bb;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n ; i++){cin >> aa;x = max(x, aa);}
    for (int i = 0; i < m ; i++){cin >> bb;y = min(y, bb);}
    if (y <= x){cout << "War" << endl;}
    else{cout << "No War" << endl;}
    return 0;
}