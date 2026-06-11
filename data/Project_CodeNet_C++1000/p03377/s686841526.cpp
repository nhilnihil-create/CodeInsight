    #include <bits/stdc++.h>
    using namespace std;

    
    int main() {
        int a, b, x; cin >> a >> b >> x;
        string ans;
        if (x < a) {
            ans = "NO";
        } else if (x > a + b) {
            ans = "NO";
        } else {
            ans = "YES";
        }
        cout << ans << endl;
        return 0;
    }