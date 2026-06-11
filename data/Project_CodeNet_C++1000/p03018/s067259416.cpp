#include<iostream>
#include<string>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
typedef long long ll;
ll sum= 0, ans = 0;
int main() {
    string s; cin >> s;
    rep(i, s.size()) {
        if (s[i] == 'A') sum++;
        else if (s.substr(i, 2) == "BC") {
            i++; ans += sum;
        }
        else sum = 0;
    }cout << ans << endl;
}