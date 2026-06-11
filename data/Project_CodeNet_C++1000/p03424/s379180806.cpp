#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    string ans = "Three";
    rep(i,n) {
        char c;
        cin >> c;
        if(c == 'Y') ans = "Four";

    }
    cout << ans << endl;
    
return 0;
}