#include <bits/stdc++.h>
using namespace std;

int main(){
    string ans = "NO";
    int a, b, x;
    cin >> a >> b >> x;
    
    if (x >= a && x <= (a + b)) {
        ans = "YES";
    }
    
    cout << ans << endl;
    
    return 0;
}
