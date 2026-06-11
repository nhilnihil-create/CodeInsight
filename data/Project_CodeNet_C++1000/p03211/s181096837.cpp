#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 100000

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int ans = INF;
    for(int i = 0; i < n-2; i++){
        stringstream ss;
        ss << s[i] << s[i+1] << s[i+2];
        int tmp;
        ss >> tmp;
        ans = min(ans, abs(tmp - 753));
    }
    cout << ans << endl;
}
