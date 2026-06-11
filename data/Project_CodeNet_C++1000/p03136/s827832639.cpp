#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string ans = "No";
    cin >> n;
    
    int sum = 0,maxlen = 1;
    for (int i = 0; i < n; i++) {
        int buf;
        cin >> buf;
        sum += buf;
        maxlen = max(maxlen,buf);
    }
    
    if (maxlen < sum - maxlen) {
        ans = "Yes";
    }
    
    cout << ans << endl;
    return 0;
}
