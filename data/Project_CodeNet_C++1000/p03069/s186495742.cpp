#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; 
    string s;
    cin >> n >> s;
    vector<int> lb(n), rw(n);
    for (int i=1; i<n; i++) {
        lb[i] = lb[i-1] + (s[i-1]=='#'); 
    }
    for (int i=n-1; i>=0; i--) {
        rw[i] = rw[i+1] + (s[i+1]=='.');
    }
    int ans = 200000;
    for (int i=0; i<n; i++) {
        ans = min(ans, lb[i]+rw[i]);
    }
    cout << ans << endl;
}