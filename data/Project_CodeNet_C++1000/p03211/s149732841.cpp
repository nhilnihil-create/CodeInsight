#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >>s;
    int n = s.size();
    
    
    int ans = 753;
    for(int i = 0; i < n-2; i++) {
        string temp = "";
        temp += s[i];
        temp += s[i+1];
        temp += s[i+2];
        int num = stoi(temp);
        ans = min(ans, abs(753-num));
    }
    cout << ans << endl;

    return 0;
}