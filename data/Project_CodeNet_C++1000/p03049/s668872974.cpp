#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int a = 0,b = 0, ba = 0;
    for(int i = 0;i < n; i++) {
        string s;
        cin >> s;
        int m = s.size();
        for(int j = 0; j + 1 < m; j++) {
            if(s[j] == 'A' && s[j + 1] == 'B') cnt++;
        }
        if(s[0] == 'B') b++;
        if(s[m - 1] == 'A') a++;
        if(s[0] == 'B' && s[m - 1] == 'A') ba++;
    }
    cnt += min(a, b);
    if(a == ba && b == ba && b > 0) cnt--;
    cout << cnt << endl;
    return 0;
}
