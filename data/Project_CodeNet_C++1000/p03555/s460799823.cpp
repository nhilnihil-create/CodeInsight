#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b, ans;
    cin >> a >> b;
    
    ans = "NO";
    
    if (a[0] == b[2] && a[1] == b[1] && a[2] == b[0]) {
        ans = "YES";
    }
    cout << ans << endl;
}
