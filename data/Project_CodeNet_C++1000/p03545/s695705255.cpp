#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    vector<int> a(4);
    rep(i, 0, s.size()) a[i] = s[i] - '0';
    rep(bi, 0, 1<<3){
        string ans;
        int sum = a[0];
        rep(i, 1, 4){
            if(bi>>(i-1)&1){
                sum += a[i];
                ans += '+';
            }
            else{
                sum -= a[i];
                ans += '-';
            }
        }
        ans += '=';
        if(sum == 7){
            rep(i, 0, 4){
                cout << a[i] << ans[i];
            }
            cout << 7 << endl;
            return 0;
        }
    }
    return 0;
}
