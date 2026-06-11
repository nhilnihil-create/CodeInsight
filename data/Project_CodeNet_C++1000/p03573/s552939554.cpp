#include <bits/stdc++.h>
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define _Pi 3.1415926535
using namespace std;
typedef long long ll;

int main(){
    vector<int> a(3);
    rep(i,3) cin >> a[i];
    sort(a.begin(),a.end());
    cout << (a[0] == a[1] ? a[2] : a[0]) << endl;
    
    return 0;
}
