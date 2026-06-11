#include <bits/stdc++.h>
using namespace std;
const int INF = 2100100100;


int main() {
    int n;
    cin >> n;
    string s = to_string(n);
    int ans = 0;
    for(int i=0;i<s.size();i++){
        ans += n % 10;
        n /= 10;
    }
    if (s.at(0)=='1'&& ans == 1){
        ans = 10;
    }
    cout << ans << endl;
    
    return 0;
}